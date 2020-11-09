package main

import "fmt"

type Folder struct {
    children []Inode
    name     string
}

func NewFolder(children []Inode, name string) *Folder {
    return &Folder{
        children: children,
        name: name,
    }
}

func (f *Folder) Print(indentation string) {
    fmt.Println(indentation + f.name)
    for _, i := range f.children {
        i.Print(indentation + indentation)
    }
}

func (f *Folder) Clone() Inode {
    cloneFolder := &Folder{name: f.name + "_clone"}
    var tempChildren []Inode
    for _, i := range f.children {
        inodeCopy := i.Clone()
        tempChildren = append(tempChildren, inodeCopy)
    }
    cloneFolder.children = tempChildren
    return cloneFolder
}
