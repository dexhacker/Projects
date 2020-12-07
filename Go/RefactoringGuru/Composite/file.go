package main

import "fmt"

type File struct {
	name string
}

func NewFile(name string) *File {
	return &File{name: name}
}

func (f *File) Search(keyword string) {
	fmt.Printf("Searching for keyword %s in file %s\n", keyword, f.name)
}
