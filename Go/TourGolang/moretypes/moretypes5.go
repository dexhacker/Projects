package main

import "fmt"

type Car struct {
    year int
    mark string
}

var (
    car1 = Car{1995, "BMW"}
    car2 = Car{mark: "Mers"}
    car3 = Car{}
    pointCar  = &Car{2000, "Mazda"}
)

func main() {
    fmt.Println(car1, pointCar, car2, car3)
}
