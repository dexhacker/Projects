package main

import "fmt"

type Doctor struct {
	next Department
}

func NewDoctor(next Department) *Doctor {
	return &Doctor{next: next}
}

func (d *Doctor) Execute(p *Patient) {
	if p.DoctorCheckUpDone {
		fmt.Println("Doctor checkup already done")
		d.next.Execute(p)
		return
	}
	fmt.Println("Doctor checking patient")
	p.DoctorCheckUpDone = true
	d.next.Execute(p)
}
