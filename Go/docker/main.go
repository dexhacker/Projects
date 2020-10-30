package main

import (
    "net/http"
)

func main() {
    http.HandleFunc("/qweqwe", func(writer http.ResponseWriter, request *http.Request) {
        println("StatusOK")
        writer.WriteHeader(http.StatusOK)
    })

    err := http.ListenAndServe(":3001", nil)
    if err != nil {
        println(err)
    }
}
