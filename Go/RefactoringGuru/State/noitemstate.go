package main

import "fmt"

type NoItemState struct {
	vendingMachine *VendingMachine
}

func NewNoItemState(machine *VendingMachine) *NoItemState {
	return &NoItemState{vendingMachine: machine}
}

func (s *NoItemState) AddItem(count int) error {
	s.vendingMachine.IncrementItemCount(count)
	s.vendingMachine.SetState(s.vendingMachine.HasItem)
	return nil
}

func (s *NoItemState) RequestItem() error {
	return fmt.Errorf("item out of stock")
}

func (s *NoItemState) InsertMoney(money int) error {
	return fmt.Errorf("item out of stock")
}

func (s *NoItemState) DispenseItem() error {
	return fmt.Errorf("item out of stock")
}
