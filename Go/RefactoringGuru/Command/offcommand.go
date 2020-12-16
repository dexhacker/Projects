package main

type OffCommand struct {
	device Device
}

func NewOffCommand(d Device) *OffCommand {
	return &OffCommand{device: d}
}

func (c *OffCommand) Execute() {
	c.device.Off()
}
