package main

import "fmt"

type Hp struct {
}

func NewHp() *Hp {
	return &Hp{}
}

func (p *Hp) PrintFile() {
	fmt.Println("Printing by a HP Printer")
}
