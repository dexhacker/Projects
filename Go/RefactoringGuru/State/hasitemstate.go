package main

import "fmt"

type HasItemState struct {
	vendingMachine *VendingMachine
}

func NewHasItemState(machine *VendingMachine) *HasItemState {
	return &HasItemState{vendingMachine: machine}
}

func (s *HasItemState) AddItem(count int) error {
	fmt.Printf("%d items added\n", count)
	s.vendingMachine.IncrementItemCount(count)
	return nil
}

func (s *HasItemState) RequestItem() error {
	if s.vendingMachine.ItemCount == 0 {
		s.vendingMachine.SetState(s.vendingMachine.NoItem)
		return fmt.Errorf("no item present")
	}
	fmt.Printf("Item requested\n")
	s.vendingMachine.SetState(s.vendingMachine.ItemRequested)
	return nil
}

func (s *HasItemState) InsertMoney(money int) error {
	return fmt.Errorf("please select item first")
}

func (s *HasItemState) DispenseItem() error {
	return fmt.Errorf("please select item first")
}
