package main

import "fmt"

type ItemRequestedState struct {
	vendingMachine *VendingMachine
}

func NewItemRequestedState(machine *VendingMachine) *ItemRequestedState {
	return &ItemRequestedState{vendingMachine: machine}
}

func (s *ItemRequestedState) AddItem(count int) error {
	return fmt.Errorf("item Dispense in progress")
}

func (s *ItemRequestedState) RequestItem() error {
	return fmt.Errorf("item already requested")
}

func (s *ItemRequestedState) InsertMoney(money int) error {
	if money < s.vendingMachine.ItemPrice {
		return fmt.Errorf("inserted money is less. Please insert %d", s.vendingMachine.ItemPrice)
	}
	fmt.Println("Money entered is ok")
	s.vendingMachine.SetState(s.vendingMachine.HasMoney)
	return nil
}

func (s *ItemRequestedState) DispenseItem() error {
	return fmt.Errorf("please insert money first")
}
