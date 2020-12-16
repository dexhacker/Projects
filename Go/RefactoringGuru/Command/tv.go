package main

import "fmt"

type Tv struct {
	isRunning bool
}

func NewTv() *Tv {
	return &Tv{}
}

func (t *Tv) On() {
	t.isRunning = true
	fmt.Println("Turning tv on")
}

func (t *Tv) Off() {
	t.isRunning = false
	fmt.Println("Turning tv off")
}
