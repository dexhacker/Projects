package main

type AdidasShoe struct {
    Shoe
}

func NewAdidasShoe() IShoe {
    return &AdidasShoe{
        Shoe{
            logo: "Adidas",
            size: 15,
        },
    }
}
