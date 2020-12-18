package main

type Originator struct {
	state string
}

func NewOriginator(state string) *Originator {
	return &Originator{state: state}
}

func (o *Originator) CreateMemento() *Memento {
	return NewMemento(o.state)
}

func (o *Originator) RestoreMemento(m *Memento) {
	o.state = m.GetSavedState()
}

func (o *Originator) SetState(state string) {
	o.state = state
}

func (o *Originator) GetState() string {
	return o.state
}
