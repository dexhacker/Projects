package main

import "errors"

func GetSportsFactory(brand string) (ISportsFactory, error) {
    if brand == "adidas" {
        return NewAdidas(), nil
    }
    if brand == "nike" {
        return NewNike(), nil
    }
    return nil, errors.New("invalid brand")
}
