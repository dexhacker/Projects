package main

import "fmt"

func main() {
	pizza := NewVeggieMania()

	pizzaWithCheese := NewCheeseTopping(pizza)

	pizzaWithCheeseAndTomato := NewTomatoTopping(pizzaWithCheese)
	fmt.Printf("Price of veggeMania with tomato and cheese topping is %d\n", pizzaWithCheeseAndTomato.GetPrice())
}
