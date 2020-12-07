package main

import "fmt"

type Mac struct {
	printer Printer
}

func NewMac() *Mac {
	return &Mac{}
}

func (m *Mac) Print() {
	fmt.Println("Print request for mac")
	m.printer.PrintFile()
}

func (m *Mac) SetPrinter(p Printer) {
	m.printer = p
}
