package main

func main() {
	shirtItem := NewItem("Nike Shirt")

	observerFirst := NewCustomer("abc@gmail.com")
	observerSecond := NewCustomer("xyz@gmail.com")

	shirtItem.Register(observerFirst)
	shirtItem.Register(observerSecond)

	shirtItem.UpdateAvailability()
}
