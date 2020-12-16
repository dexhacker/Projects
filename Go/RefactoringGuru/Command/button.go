package main

type Button struct {
	command Command
}

func NewButton(c Command) *Button {
	return &Button{command: c}
}

func (b *Button) Press() {
	b.command.Execute()
}
