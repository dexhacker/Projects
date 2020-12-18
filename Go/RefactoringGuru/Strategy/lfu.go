package main

import "fmt"

type Lfu struct {
}

func NewLfu() *Lfu {
	return &Lfu{}
}

func (l *Lfu) Evict(c *Cache) {
	fmt.Println("Evicting by lfu strategy")
}
