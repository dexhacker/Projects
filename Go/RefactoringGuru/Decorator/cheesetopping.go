package main

type CheeseTopping struct {
	pizza Pizza
}

func NewCheeseTopping(pizza Pizza) *CheeseTopping {
	return &CheeseTopping{pizza: pizza}
}

func (c *CheeseTopping) GetPrice() int {
	pizzaPrice := c.pizza.GetPrice()
	return pizzaPrice + 10
}
