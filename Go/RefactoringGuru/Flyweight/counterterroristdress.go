package main

type CounterTerroristDress struct {
	color string
}

func NewCounterTerroristDress() *CounterTerroristDress {
	return &CounterTerroristDress{color: "green"}
}

func (ct *CounterTerroristDress) GetColor() string {
	return ct.color
}
