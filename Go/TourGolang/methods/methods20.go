package main

import (
    "fmt"
    "math"
)

type ErrNegativeSqrt float64

func (errNegativeSqrt ErrNegativeSqrt) Error() string {
    return fmt.Sprintf("cannot Sqrt negative number: %g", errNegativeSqrt)
}

func Sqrt(x float64) (float64, error) {
    if x < 0 {
        return 0, ErrNegativeSqrt(x)
    }
    return math.Sqrt(x), nil
}

func main() {
    fmt.Println(Sqrt(2))
    fmt.Println(Sqrt(-2))
}
