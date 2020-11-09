package main

import "fmt"

type Gun struct {
    name string
    power int
}

func (g *Gun) Shot() {
    fmt.Printf("%s shot %v", g.name, g.power)
}
