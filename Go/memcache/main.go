package main

import (
    "github.com/bradfitz/gomemcache/memcache"
    "log"
)

func main()  {
    client := memcache.New("localhost:11211")
    err := client.Set(&memcache.Item{Key: "foo", Value: []byte("my value")})
    if err != nil {
        log.Fatal("Set error: ", err)
    }

    item, err := client.Get("foo")
    if err != nil {
        log.Fatal("Get error: ", err)
    }

    log.Print("Item: ", string(item.Value))

    qwe, err := client.Get("qwe")
    if err != nil {
        log.Fatal("Get qwe error: ", err)
    }
    log.Print("QWE: ", qwe.Value)
}
