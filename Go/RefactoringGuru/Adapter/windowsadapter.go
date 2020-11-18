package main

import "fmt"

type WindowsAdapter struct {
	WindowsMachine *Windows
}

func NewWindowsAdapter(w *Windows) *WindowsAdapter {
	return &WindowsAdapter{WindowsMachine: w}
}

func (w *WindowsAdapter) insertIntoLightningPort() {
	fmt.Println("Adapter converts Lightning signal to USB.")
	w.WindowsMachine.insertIntoUSBPort()
}
