package main

import "fmt"

func main() {
	game := NewGame()

	game.AddTerrorist()
	game.AddTerrorist()
	game.AddTerrorist()
	game.AddTerrorist()

	game.AddCounterTerrorist()
	game.AddCounterTerrorist()
	game.AddCounterTerrorist()

	dressFactoryInstance := GetDressFactorySingleInstance()

	for dressType, dress := range dressFactoryInstance.dressMap {
		fmt.Printf("DressColorType: %s\nDressColor: %s\n", dressType, dress.GetColor())
	}
}
