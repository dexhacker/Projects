package main

import "fmt"

type VendingMachine struct {
	HasItem       State
	ItemRequested State
	HasMoney      State
	NoItem        State

	currentState State

	ItemCount int
	ItemPrice int
}

func NewVendingMachine(itemCount, itemPrice int) *VendingMachine {
	vendingMachine := &VendingMachine{ItemCount: itemCount, ItemPrice: itemPrice}

	hasItemState := NewHasItemState(vendingMachine)
	itemRequestedState := NewItemRequestedState(vendingMachine)
	hasMoneyState := NewHasMoneyState(vendingMachine)
	noItemState := NewNoItemState(vendingMachine)

	vendingMachine.SetState(hasItemState)
	vendingMachine.HasItem = hasItemState
	vendingMachine.ItemRequested = itemRequestedState
	vendingMachine.HasMoney = hasMoneyState
	vendingMachine.NoItem = noItemState
	return vendingMachine
}

func (v *VendingMachine) RequestItem() error {
	return v.currentState.RequestItem()
}

func (v *VendingMachine) AddItem(count int) error {
	return v.currentState.AddItem(count)
}

func (v *VendingMachine) InsertMoney(money int) error {
	return v.currentState.InsertMoney(money)
}

func (v *VendingMachine) DispenseItem() error {
	return v.currentState.DispenseItem()
}

func (v *VendingMachine) SetState(s State) {
	v.currentState = s
}

func (v *VendingMachine) IncrementItemCount(count int) {
	fmt.Printf("Adding %d items\n", count)
	v.ItemCount = v.ItemCount + count
}
