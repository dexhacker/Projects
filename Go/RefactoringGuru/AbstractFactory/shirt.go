package main

import "fmt"

type Shirt struct {
    logo string
    size int
}

func (s *Shirt) PrintShirtInfo() {
    fmt.Printf("Shirt Logo: %s, size: %v", s.logo, s.size)
    fmt.Println()
}
