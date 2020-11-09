package main

import (
    "log"
    "net/http"
)

func main() {
    http.HandleFunc("/health", func(writer http.ResponseWriter, request *http.Request) {
        log.Print("Handle HEALTH")
        writer.WriteHeader(http.StatusOK)
    })

    err := http.ListenAndServe(":3001", nil)
    if err != nil {
        log.Fatal(err)
    }
}
