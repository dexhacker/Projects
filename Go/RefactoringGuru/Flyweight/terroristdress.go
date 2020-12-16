package main

type TerroristDress struct {
	color string
}

func NewTerroristDress() *TerroristDress {
	return &TerroristDress{color: "red"}
}

func (t *TerroristDress) GetColor() string {
	return t.color
}
