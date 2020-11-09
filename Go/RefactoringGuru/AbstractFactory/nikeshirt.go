package main

type NikeShirt struct {
    Shirt
}

func NewNikeShirt() IShirt {
    return &NikeShirt{
        Shirt{
            logo: "Nike",
            size: 21,
        },
    }
}
