package main

import (
    "context"
    "github.com/go-redis/redis/v8"
    "log"
)

var ctx = context.Background()

func main()  {
    redisDataBase := redis.NewClient(&redis.Options{Addr: "localhost:6379"})

    err := redisDataBase.Set(ctx, "age", 24, 0).Err()
    if err != nil {
        log.Fatal(err)
    }

    age, err := redisDataBase.Get(ctx, "age").Result()
    if err != nil {
        log.Fatal(err)
    }

    log.Print("Age: ", age)

    someKey, err := redisDataBase.Get(ctx, "someKey").Result()
    if err != nil {
        log.Fatal("someKey error", err)
    }
    log.Print("someKey: ", someKey)
}
