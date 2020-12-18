package main

type Rectangle struct {
	l int
	b int
}

func NewRectangle(l, b int) *Rectangle {
	return &Rectangle{l: l, b: b}
}

func (r *Rectangle) Accept(v Visitor) {
	v.VisitForRectangle(r)
}

func (r *Rectangle) GetType() string {
	return "Rectangle"
}
