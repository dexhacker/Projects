package httphandlers

import (
    "database/sql"
    "encoding/json"
    "github.com/gorilla/mux"
    "net/http"
)

func GetUser(writer http.ResponseWriter, request *http.Request) {
    variables := mux.Vars(request)

    db, err := sql.Open(
        "postgres",
        "host=localhost port=5432 user=postgres password=qwerty dbname=example_postgres sslmode=disable",
    )
    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }

    if err := db.Ping(); err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }
    type responseBody struct {
        Name  string
        Email string
        Age   int
    }

    res := &responseBody{}
    err = db.QueryRow(
        "SELECT name, email, age FROM users WHERE id = $1",
        variables["uuid"],
    ).Scan(&res.Name, &res.Email, &res.Age)

    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }

    writer.Header().Set("Content-Type", "application/json")
    writer.WriteHeader(http.StatusOK)
    err = json.NewEncoder(writer).Encode(res)
    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }
}
