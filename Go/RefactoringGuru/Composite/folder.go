package main

import "fmt"

type Folder struct {
	components []Component
	name string
}

func NewFolder(name string) *Folder {
	return &Folder{name : name}
}

func (f *Folder) Search(keyword string) {
	fmt.Printf("Serching recursively for keyword %s in folder %s\n", keyword, f.name)
	for _, component := range f.components {
		component.Search(keyword)
	}
}

func (f *Folder) Add(c Component) {
	f.components = append(f.components, c)
}
