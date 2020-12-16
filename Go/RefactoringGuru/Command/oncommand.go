package main

type OnCommand struct {
	device Device
}

func NewOnCommand(d Device) *OnCommand {
	return &OnCommand{device: d}
}

func (c *OnCommand) Execute() {
	c.device.On()
}
