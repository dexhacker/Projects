package main

type Adidas struct {
    shoe IShoe
    shirt IShirt
}

func NewAdidas() ISportsFactory {
    shoe := NewAdidasShoe()
    shirt := NewAdidasShirt()
    return &Adidas{
        shoe: shoe,
        shirt: shirt,
    }
}

func (a *Adidas) PrintForm() {
    a.shoe.PrintShoeInfo()
    a.shirt.PrintShirtInfo()
}
