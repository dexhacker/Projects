package main

import "fmt"

func main() {
    ak47, _ := GetGun("ak47")
    musket, _ := GetGun("musket")

    ak47.Shot()
    fmt.Println()
    musket.Shot()
}
