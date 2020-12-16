package main

func main() {
	tv := NewTv()

	onCommand := NewOnCommand(tv)
	offCommand := NewOffCommand(tv)

	onButton := NewButton(onCommand)
	onButton.Press()

	offButton := NewButton(offCommand)
	offButton.Press()
}
