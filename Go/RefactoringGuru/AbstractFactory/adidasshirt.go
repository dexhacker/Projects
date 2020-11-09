package main

type AdidasShirt struct {
    Shirt
}

func NewAdidasShirt() IShirt {
    return &AdidasShirt{
        Shirt{
            logo: "Adidas",
            size: 16,
        },
    }
}
