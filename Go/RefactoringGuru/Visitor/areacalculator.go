package main

import "fmt"

type AreaCalculator struct {
	area int
}

func NewAreaCalculator() *AreaCalculator {
	return &AreaCalculator{}
}

func (a *AreaCalculator) VisitForSquare(s *Square) {
	fmt.Println("Calculating area for square")
}

func (a *AreaCalculator) VisitForCircle(c *Circle) {
	fmt.Println("Calculating area for circle")
}

func (a *AreaCalculator) VisitForRectangle(r *Rectangle) {
	fmt.Println("Calculating area for rectangle")
}
