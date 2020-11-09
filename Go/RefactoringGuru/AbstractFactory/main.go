package main

func main() {
    adidasFactory, _ := GetSportsFactory("adidas")
    nikeFactory, _ := GetSportsFactory("nike")

    adidasFactory.PrintForm()
    nikeFactory.PrintForm()
}
