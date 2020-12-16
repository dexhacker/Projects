package main

type Collection interface {
	CreateIterator() Iterator
}
