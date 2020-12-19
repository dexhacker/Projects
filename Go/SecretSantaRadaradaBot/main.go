package main

func main() {
	connection := NewConnection("1496959189:AAEqLDfc3A7oiLaSCJ8VIRLm8vaWl-FoxOI")
	connection.Connect()
	connection.SetConf()
	connection.TestConnection()
	connection.StartListening()
}
