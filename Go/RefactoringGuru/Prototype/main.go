package main

import "fmt"

func main() {
    file1 := NewFile("File1")
    file2 := NewFile("File2")
    file3 := NewFile("File3")

    folder1 := NewFolder([]Inode{file1}, "Folder1")
    folder2 := NewFolder([]Inode{folder1, file2, file3}, "Folder2")

    fmt.Println("\nPrinting hierarchy for Folder2")
    folder2.Print("  ")

    cloneFolder := folder2.Clone()
    fmt.Println("\nPrinting hierarchy for clone Folder")
    cloneFolder.Print("  ")
}
