package httphandlers

import (
    "encoding/json"
    "github.com/gorilla/mux"
    "net/http"
    "database/sql"
)

func PutUser(writer http.ResponseWriter, request *http.Request) {
    variables := mux.Vars(request)

    type requestBody struct {
        Name  string `json:"name,required"`
        Email string `json:"email,required"`
        Age   int    `json:"age,required"`
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
       "UPDATE users SET name = $1, email = $2, age = $3 WHERE id = $4",
        req.Name,
        req.Email,
        req.Age,
       variables["uuid"],
    )

    if err != nil {
       logger.Error(err)
       writer.WriteHeader(http.StatusInternalServerError)
       return
    }

    writer.WriteHeader(http.StatusOK)
}
