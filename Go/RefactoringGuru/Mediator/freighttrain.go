package main

import "fmt"

type FreightTrain struct {
	mediator Mediator
}

func NewFreightTrain(mediator Mediator) *FreightTrain {
	return &FreightTrain{mediator: mediator}
}

func (p *FreightTrain) Arrive() {
	if !p.mediator.CanArrive(p) {
		fmt.Println("FreightTrain: Arrival blocked, waiting")
		return
	}
	fmt.Println("FreightTrain: Arrived")
}

func (p *FreightTrain) Depart() {
	fmt.Println("FreightTrain: Leaving")
	p.mediator.NotifyAboutDeparture()
}

func (p *FreightTrain) PermitArrival() {
	fmt.Println("FreightTrain: Arrival permitted, arriving")
	p.Arrive()
}

