package main

import "fmt"

type Windows struct {
}

func NewWindows() *Windows {
	return &Windows{}
}

func (w *Windows) insertIntoUSBPort() {
	fmt.Println("USB connector is plugged into windows machine.")
}
