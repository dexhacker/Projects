package main

import "fmt"

type Fifo struct {
}

func NewFifo() *Fifo {
	return &Fifo{}
}

func (f *Fifo) Evict(c *Cache) {
	fmt.Println("Evicting by fifo strategy")
}
