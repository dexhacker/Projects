package main

func main() {
	lfu := NewLfu()
	cache := NewCache(lfu)

	cache.Add("a", "1")
	cache.Add("b", "2")
	cache.Add("c", "3")

	lru := NewLru()
	cache.SetEvictionAlgo(lru)

	cache.Add("e", "4")

	fifo := NewFifo()
	cache.SetEvictionAlgo(fifo)

	cache.Add("e", "5")
}
