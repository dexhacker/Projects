package main

import "fmt"

type HasMoneyState struct {
	vendingMachine *VendingMachine
}

func NewHasMoneyState(machine *VendingMachine) *HasMoneyState {
	return &HasMoneyState{vendingMachine: machine}
}

func (s *HasMoneyState) AddItem(count int) error {
	return fmt.Errorf("item dispense in progress")
}

func (s *HasMoneyState) RequestItem() error {
	return fmt.Errorf("item dispense in progress")
}

func (s *HasMoneyState) InsertMoney(money int) error {
	return fmt.Errorf("item out of stock")
}

func (s *HasMoneyState) DispenseItem() error {
	fmt.Println("Dispensing Item")
	s.vendingMachine.IncrementItemCount(-1)
	if s.vendingMachine.ItemCount == 0 {
		s.vendingMachine.SetState(s.vendingMachine.NoItem)
	} else {
		s.vendingMachine.SetState(s.vendingMachine.HasItem)
	}
	return nil
}
