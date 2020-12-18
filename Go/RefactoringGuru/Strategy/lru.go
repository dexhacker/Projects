package main

import "fmt"

type Lru struct {
}

func NewLru() *Lru {
	return &Lru{}
}

func (l *Lru) Evict(c *Cache) {
	fmt.Println("Evicting by lru strategy")
}
