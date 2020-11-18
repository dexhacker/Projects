package main

func main() {
	client := NewClient()
	mac := NewMac()

	client.insertLightningConnectorIntoComputer(mac)

	windowsMachine := NewWindows()
	windowsMachineAdapter := NewWindowsAdapter(windowsMachine)

	client.insertLightningConnectorIntoComputer(windowsMachineAdapter)
}
