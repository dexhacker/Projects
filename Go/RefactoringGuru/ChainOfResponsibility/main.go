package main

func main() {
	patient := NewPatient("abc")

	cashier := NewCashier(nil)
	medical := NewMedical(cashier)
	doctor := NewDoctor(medical)
	reception := NewReception(doctor)

	reception.Execute(patient)
}
