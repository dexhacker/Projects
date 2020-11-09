package main

import "fmt"

type Shoe struct {
    logo string
    size int
}

func (s *Shoe) PrintShoeInfo() {
    fmt.Printf("Shoe Logo: %s, size: %v", s.logo, s.size)
    fmt.Println()
}
