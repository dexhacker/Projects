package main

import "fmt"

type MiddleCoordinates struct {
	x int
	y int
}

func NewMiddleCoordinates() *MiddleCoordinates {
	return &MiddleCoordinates{}
}

func (m *MiddleCoordinates) VisitForSquare(s *Square) {
	fmt.Println("Calculating middle point coordinates for square")
}

func (m *MiddleCoordinates) VisitForCircle(c *Circle) {
	fmt.Println("Calculating middle point coordinates for circle")
}

func (m *MiddleCoordinates) VisitForRectangle(r *Rectangle) {
	fmt.Println("Calculating middle point coordinates for rectangle")
}
