package main

type Server interface {
	HandleRequest(string, string) (int, string)
}
