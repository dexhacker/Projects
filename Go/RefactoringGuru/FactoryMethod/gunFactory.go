package main

import "errors"

func GetGun(gunType string) (IGun, error) {
    if gunType == "ak47" {
        return NewAk47(), nil
    }
    if gunType == "musket" {
        return NewMusket(), nil
    }
    return nil, errors.New("wrong gun type passed")
}
