package main

import (
    "github.com/Projects/Go/postgres/internal/httphandlers"
    "github.com/gorilla/mux"
    "github.com/sirupsen/logrus"
    "net/http"
)

var logger = logrus.New()

func main()  {
    logger.Info("Starting...")
    router := mux.NewRouter()

    router.HandleFunc("/users", httphandlers.CreateUser).Methods("POST")
    router.HandleFunc("/users/{uuid}", httphandlers.GetUser).Methods("GET")
    router.HandleFunc("/users/{uuid}", httphandlers.PutUser).Methods("PUT")
    router.HandleFunc("/users/{uuid}", httphandlers.PatchUser).Methods("PATCH")
    router.HandleFunc("/users/{uuid}", httphandlers.DeleteUser).Methods("DELETE")
    if err := http.ListenAndServe(":8000", router); err != nil {
        logger.Error(err)
    }
}
