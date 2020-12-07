package main

type TomatoTopping struct {
	pizza Pizza
}

func NewTomatoTopping(pizza Pizza) *TomatoTopping {
	return &TomatoTopping{pizza: pizza}
}

func (t *TomatoTopping) GetPrice() int {
	pizzaPrice := t.pizza.GetPrice()
	return pizzaPrice + 7
}
