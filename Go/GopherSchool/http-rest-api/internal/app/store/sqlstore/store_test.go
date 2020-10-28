package sqlstore_test

import (
    "os"
    "testing"
)

var (
    databaseUrl string
)

func TestMain(m *testing.M)  {
    databaseUrl = os.Getenv("DATABASE_URL")
    if databaseUrl == "" {
        databaseUrl = "host=localhost user=postgres password=qwerty dbname=restapi_test sslmode=disable"
    }

    os.Exit(m.Run())
}
