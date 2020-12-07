package main

import "fmt"

type Windows struct {
	printer Printer
}

func NewWindows() *Windows {
	return &Windows{}
}

func (w *Windows) Print() {
	fmt.Println("Print request for windows")
	w.printer.PrintFile()
}

func (w *Windows) SetPrinter(p Printer) {
	w.printer = p
}
