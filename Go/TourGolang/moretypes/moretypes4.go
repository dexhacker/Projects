package main

import "fmt"

type Dog struct {
    age int
    name string
}

func main() {
    dog := Dog{1, "Net"}
    d := &dog
    d.name = "Mat"
    fmt.Println(d)
}
