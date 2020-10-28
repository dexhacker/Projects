package main

import (
    "fmt"
    "math"
)

type Vertex10 struct {
    X, Y float64
}

func (v Vertex10) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func AbsFunc(v Vertex10) float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
    v := Vertex10{3, 4}
    fmt.Println(v.Abs())
    fmt.Println(AbsFunc(v))

    p := &Vertex10{4, 3}
    fmt.Println(p.Abs())
    fmt.Println(AbsFunc(*p))
}
