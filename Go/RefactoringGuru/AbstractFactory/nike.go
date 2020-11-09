package main

type Nike struct {
    shoe IShoe
    shirt IShirt
}

func NewNike() ISportsFactory {
    shoe := NewNikeShoe()
    shirt := NewNikeShirt()
    return &Nike{
        shoe: shoe,
        shirt: shirt,
    }
}

func (n *Nike) PrintForm() {
    n.shoe.PrintShoeInfo()
    n.shirt.PrintShirtInfo()
}
