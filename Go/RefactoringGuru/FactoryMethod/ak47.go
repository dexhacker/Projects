package main

type Ak47 struct {
    Gun
}

func NewAk47() IGun {
    return &Ak47{
        Gun{
            name: "AK47 gun",
            power: 4,
        },
    }
}
