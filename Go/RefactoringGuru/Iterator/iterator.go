package main

type Iterator interface {
	HasNext() bool
	GetNext() *User
}
