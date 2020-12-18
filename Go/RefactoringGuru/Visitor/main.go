package main

import "fmt"

func main() {
	square := NewSquare(2)
	circle := NewCircle(3)
	rectangle := NewRectangle(2, 3)

	areaCalculator := NewAreaCalculator()
	middleCoordinates := NewMiddleCoordinates()

	square.Accept(areaCalculator)
	circle.Accept(areaCalculator)
	rectangle.Accept(areaCalculator)

	fmt.Println()

	square.Accept(middleCoordinates)
	circle.Accept(middleCoordinates)
	rectangle.Accept(middleCoordinates)
}
