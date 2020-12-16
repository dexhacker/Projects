package main

import "fmt"

type Medical struct {
	next Department
}

func NewMedical(next Department) *Medical {
	return &Medical{next: next}
}

func (m *Medical) Execute(p *Patient) {
	if p.MedicineDone {
		fmt.Println("Medicine already given to patient")
		m.next.Execute(p)
		return
	}
	fmt.Println("Medical giving medicine to patient")
	p.MedicineDone = true
	m.next.Execute(p)
}
