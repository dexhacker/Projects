package main

import "fmt"

func main() {
    normalBuilder := GetBuilder("normal")
    iglooBuilder := GetBuilder("igloo")

    director := NewDirector(normalBuilder)
    normalHouse := director.BuildHouse()

    fmt.Printf("Normal House Door Type: %s\n", normalHouse.doorType)
    fmt.Printf("Normal House Window Type: %s\n", normalHouse.windowType)
    fmt.Printf("Normal House Num Floor: %d\n", normalHouse.floor)

    director.SetBuilder(iglooBuilder)
    iglooHouse := director.BuildHouse()

    fmt.Printf("\nIgloo House Door Type: %s\n", iglooHouse.doorType)
    fmt.Printf("Igloo House Window Type: %s\n", iglooHouse.windowType)
    fmt.Printf("Igloo House Num Floor: %d\n", iglooHouse.floor)
}
