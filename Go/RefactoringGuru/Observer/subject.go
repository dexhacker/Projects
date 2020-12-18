package main

type Subject interface {
	Register(Observer)
	Deregister(Observer)
	NotifyAll()
}
