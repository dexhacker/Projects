package main

import "fmt"

const (
	TerroristDressType = "tDress"
	CounterTerroristDressType = "ctDress"
)

var dressFactorySingleInstance = &dressFactory{
	dressMap: make(map[string]Dress),
}

type dressFactory struct {
	dressMap map[string]Dress
}

func GetDressFactorySingleInstance() *dressFactory {
	return dressFactorySingleInstance
}

func (d *dressFactory) getDressByType(dressType string) (Dress, error) {
	if d.dressMap[dressType] != nil {
		return d.dressMap[dressType], nil
	}

	if dressType == TerroristDressType {
		d.dressMap[dressType] = NewTerroristDress()
		return d.dressMap[dressType], nil
	}

	if dressType == CounterTerroristDressType {
		d.dressMap[dressType] = NewCounterTerroristDress()
		return d.dressMap[dressType], nil
	}

	return nil, fmt.Errorf("wrong dress type passed")
}
