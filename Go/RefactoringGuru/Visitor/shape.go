package main

type Shape interface {
	GetType() string
	Accept(Visitor)
}
