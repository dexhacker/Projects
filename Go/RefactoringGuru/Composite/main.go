package main

func main() {
	file1 := NewFile("File1")
	file2 := NewFile("File2")
	file3 := NewFile("File3")

	folder1 := NewFolder("Folder1")
	folder1.Add(file1)

	folder2 := NewFolder("Folder2")
	folder2.Add(file2)
	folder2.Add(file3)
	folder2.Add(folder1)

	folder2.Search("rose")
}
