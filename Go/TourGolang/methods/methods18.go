package main

import "fmt"

type IPAddr [4]byte

func (apAddr IPAddr) String() string {
    return fmt.Sprintf("%v.%v.%v.%v", apAddr[0], apAddr[1], apAddr[2], apAddr[3])
}

func main() {
    hosts := map[string]IPAddr{
        "loopback":  {127, 0, 0, 1},
        "googleDNS": {8, 8, 8, 8},
    }
    for name, ip := range hosts {
        fmt.Printf("%v: %v\n", name, ip)
    }
}
