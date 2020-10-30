package httphandlers

import (
    "database/sql"
    "encoding/json"
    "github.com/sirupsen/logrus"
    "net/http"

    _ "github.com/lib/pq"
)

var logger = logrus.New()

func CreateUser(writer http.ResponseWriter, request *http.Request) {
    type requestBody struct {
        Name  string `json:"name"`
        Email string `json:"email"`
        Age   int    `json:"age"`
    }

    req := &requestBody{}
    if err := json.NewDecoder(request.Body).Decode(req); err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusBadRequest)
        if err := json.NewEncoder(writer).Encode(map[string]string{
            "error": err.Error(),
        }); err != nil {
            writer.WriteHeader(http.StatusInternalServerError)
            return
        }
        return
    }

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
        "INSERT INTO users (name, email, age) VALUES ($1, $2, $3)",
        req.Name,
        req.Email,
        req.Age,
    )

    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }

    writer.WriteHeader(http.StatusCreated)
}
