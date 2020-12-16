package main

type Mediator interface {
	CanArrive(Train) bool
	NotifyAboutDeparture()
}
