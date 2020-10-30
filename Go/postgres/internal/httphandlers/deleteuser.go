package httphandlers

import (
    "database/sql"
    "github.com/gorilla/mux"
    "net/http"
)

func DeleteUser(writer http.ResponseWriter, request *http.Request) {
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

    _, err = db.Query(
        "DELETE FROM users WHERE id = $1",
        variables["uuid"],
    )

    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }

    writer.WriteHeader(http.StatusOK)
}
