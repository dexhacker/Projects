package main

import "fmt"

type Cashier struct {
	next Department
}

func NewCashier(next Department) *Cashier {
	return &Cashier{next: next}
}

func (c *Cashier) Execute(p *Patient) {
	if p.PaymentDone {
		fmt.Println("Payment Done")
		return
	}
	p.PaymentDone = true
	fmt.Println("Cashier getting money from patient")
}
