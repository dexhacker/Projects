package main

import "fmt"

type Epson struct {
}

func NewEpson() *Epson {
	return &Epson{}
}

func (p *Epson) PrintFile() {
	fmt.Println("Printing by a EPSON Printer")
}
