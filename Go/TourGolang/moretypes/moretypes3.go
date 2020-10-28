package main

import "fmt"

type Cat struct {
    age int
    name string
}

func main() {
    v := Cat{1, "Tim"}
    v.name = "Tom"
    fmt.Println(v.name)
}
