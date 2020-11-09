package main

type NikeShoe struct {
    Shoe
}

func NewNikeShoe() IShoe {
    return &NikeShoe{
        Shoe{
            logo: "Nike",
            size: 20,
        },
    }
}
