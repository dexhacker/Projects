package httphandlers

import (
    "database/sql"
    "encoding/json"
    "fmt"
    "github.com/gorilla/mux"
    "net/http"
)

func PatchUser(writer http.ResponseWriter, request *http.Request) {
    variables := mux.Vars(request)

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

    query := "UPDATE users SET "
    if req.Age != 0 {
        query += fmt.Sprintf("age = %v ", req.Age)
    }
    if req.Email != "" {
        query += fmt.Sprintf("email = '%v' ", req.Email)
    }
    if req.Name != "" {
        query += fmt.Sprintf("name = '%v' ", req.Name)
    }
    query += fmt.Sprintf("WHERE id = '%v'", variables["uuid"])

    logger.Info(query)

    _, err = db.Query(query)

    if err != nil {
        logger.Error(err)
        writer.WriteHeader(http.StatusInternalServerError)
        return
    }

    writer.WriteHeader(http.StatusOK)
}
