package main

import (
    "database/sql"
    "github.com/ClickHouse/clickhouse-go"
    "log"
    "time"

    _ "github.com/ClickHouse/clickhouse-go"
)

func main() {
    database, err := sql.Open("clickhouse", "tcp://localhost:9000?debug=true")
    if err != nil {
        log.Fatal("Open connection error: ", err)
    }

    defer func() {
        err := database.Close()
        if err != nil {
            log.Fatal("Database close error: ", err)
        }
    }()

    err = database.Ping()
    if err != nil {
        log.Fatal("Ping error: ", err)
    }

    _, err = database.Exec(`
        CREATE TABLE IF NOT EXISTS example (
			country_code FixedString(2),
			os_id        UInt8,
			browser_id   UInt8,
			categories   Array(Int16),
			action_day   Date,
			action_time  DateTime
		) engine=Memory
    `)
    if err != nil {
        log.Fatal("Create database error: ", err)
    }

    begin, err := database.Begin()
    if err != nil {
        log.Fatal("Begin error: ", err)
    }

    prepare, err := begin.Prepare(
        "INSERT INTO example (country_code, os_id, browser_id, categories, action_day, action_time) VALUES (?, ?, ?, ?, ?, ?)",
    )
    if err != nil {
        log.Fatal("Insert into table error: ", err)
    }

    defer func() {
        err := prepare.Close()
        if err != nil {
            log.Fatal("Prepare close error: ", err)
        }
    }()

    _, err = prepare.Exec(
        "RU",
        100,
        1000,
        clickhouse.Array([]int16{1, 2, 3}),
        time.Now(),
        time.Now(),
    )
    if err != nil {
        log.Fatal("Prepare exec error: ", err)
    }

    err = begin.Commit()
    if err != nil {
        log.Fatal("Commit error: ", err)
    }

    rows, err := database.Query("SELECT country_code, os_id, browser_id, categories, action_day, action_time FROM example")
    if err != nil {
        log.Fatal("Query error: ", err)
    }


    for rows.Next() {
        var (
            country               string
                os, browser           uint8
            categories            []int16
            actionDay, actionTime time.Time
        )

        err := rows.Scan(&country, &os, &browser, &categories, &actionDay, &actionTime)
        if err != nil {
            log.Fatal("Scan error: ", err)
        }

        log.Printf(
            "country: %s, os: %d, browser: %d, categories: %v, action_day: %s, action_time: %s",
            country,
            os,
            browser,
            categories,
            actionDay,
            actionTime,
        )
    }

    _, err = database.Exec("DROP TABLE example")
    if err != nil {
        log.Fatal("Drop table error: ", err)
    }
}
