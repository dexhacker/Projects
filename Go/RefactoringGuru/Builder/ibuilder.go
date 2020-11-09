package main

type IBuilder interface {
    SetWindowType()
    SetDoorType()
    SetNumFloor()
    GetHouse() House
}
