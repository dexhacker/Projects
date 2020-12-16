package main

import "fmt"

type PassengerTrain struct {
	mediator Mediator
}

func NewPassengerTrain(mediator Mediator) *PassengerTrain {
	return &PassengerTrain{mediator: mediator}
}

func (p *PassengerTrain) Arrive() {
	if !p.mediator.CanArrive(p) {
		fmt.Println("PassengerTrain: Arrival blocked, waiting")
		return
	}
	fmt.Println("PassengerTrain: Arrived")
}

func (p *PassengerTrain) Depart() {
	fmt.Println("PassengerTrain: Leaving")
	p.mediator.NotifyAboutDeparture()
}

func (p *PassengerTrain) PermitArrival() {
	fmt.Println("PassengerTrain: Arrival permitted, arriving")
	p.Arrive()
}
