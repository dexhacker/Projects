package main

import (
    "context"
    "fmt"
    "github.com/segmentio/kafka-go"
    "log"
    "time"
)

func main()  {
    writeMessage()
    consumeMessage()
}

func writeMessage() {
    topic := "kafka-example"
    connection, err := kafka.DialLeader(context.Background(), "tcp", "localhost:9092", topic, 0)
    if err != nil {
        log.Fatal("failed to dial leader:", err)
    }

    err = connection.SetWriteDeadline(time.Now().Add(10 * time.Second))
    if err != nil {
        log.Fatal("failed to set write dead line:", err)
    }

    someInt, err := connection.Write([]byte("Hello world"))
    if err != nil {
        log.Fatal("failed to write message:", err)
    }

    log.Println("PRINT someInt:", someInt)

    if err := connection.Close(); err != nil {
        log.Fatal("failed to close writer:", err)
    }
}

func consumeMessage() {
    topic := "kafka-example"

    reader := kafka.NewReader(kafka.ReaderConfig{
        Brokers: []string{"localhost:9092"},
        Topic: topic,
    })

    message, err := reader.ReadMessage(context.Background())
    if err != nil {
        log.Fatal("failed to read message:", err)
    }

    fmt.Printf("message at offset %d: %s = %s\n", message.Offset, string(message.Key), string(message.Value))

    if err := reader.Close(); err != nil {
        log.Fatal("failed to close reader:", err)
    }
}
