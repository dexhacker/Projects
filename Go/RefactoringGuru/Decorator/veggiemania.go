package main

type VeggieMania struct {
}

func NewVeggieMania() *VeggieMania {
	return &VeggieMania{}
}

func (p *VeggieMania) GetPrice() int {
	return 15
}
