package main

import "fmt"

type Wallet struct {
	balance int
}

func NewWallet() *Wallet {
	return &Wallet{balance: 0}
}

func (w *Wallet) CreditBalance(amount int) {
	w.balance += amount
	fmt.Println("Wallet balance added successfully")
	return
}

func (w *Wallet) DebitBalance(amount int) error {
	if w.balance < amount {
		return fmt.Errorf("balance is not sufficient")
	}
	fmt.Println("Wallet balance is Sufficient")
	w.balance -= amount
	return nil
}
