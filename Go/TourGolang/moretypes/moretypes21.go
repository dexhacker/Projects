package main

import "fmt"

type Vertex5 struct {
    Lat, Long float64
}

var m3 = map[string]Vertex5{
    "Bell Labs": {40.68433, -74.39967},
    "Google":    {37.42202, -122.08408},
}

func main() {
    fmt.Println(m3)
}
