package main

import "fmt"

type Vertex9 struct {
    X, Y float64
}

func (v *Vertex9) Scale(f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}

func ScaleFunc(v *Vertex9, f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}

func main() {
    v := Vertex9{3, 4}
    v.Scale(2)
    ScaleFunc(&v, 10)

    p := &Vertex9{4, 3}
    p.Scale(3)
    ScaleFunc(p, 8)

    fmt.Println(v, p)
}
