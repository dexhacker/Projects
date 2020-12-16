package main

import "fmt"

type Reception struct {
	next Department
}

func NewReception(next Department) *Reception {
	return &Reception{next: next}
}

func (r *Reception) Execute(p *Patient) {
	if p.RegistrationDone {
		fmt.Println("Patient registration already done")
		r.next.Execute(p)
		return
	}
	fmt.Println("Reception registering patient")
	p.RegistrationDone = true
	r.next.Execute(p)
}
