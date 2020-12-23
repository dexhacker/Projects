package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"testing"
)

type BotTest struct {
}

func (b *BotTest) Send(c tgbotapi.Chattable) (tgbotapi.Message, error) {
	fmt.Println("Bot Send")
	return tgbotapi.Message{}, nil
}

func TestGetReplyMessage(t *testing.T)  {
	fmt.Println("Start test TestGetReplyMessage")
	message := createMessage()
	data := newData()
	bot := &BotTest{}

	want := "Распределение завершено!"
	if got := NewRun(message, data, bot).GetReplyMessage(); got != want {
		t.Errorf("NewRun(message, data, bot).GetReplyMessage() = %q, want %q", got, want)
	} else {
		fmt.Println("Success")
	}
}

func createMessage() *tgbotapi.Message {
	return &tgbotapi.Message{
		From: &tgbotapi.User{
			ID: 1,
		},
	}
}

func newData() *Data {
	data := NewData()

	chat := &tgbotapi.Chat{ID: 1}

	data.AddUser(&tgbotapi.User{ID: 1, UserName: "user1"}, chat)
	data.AddUser(&tgbotapi.User{ID: 2, UserName: "user2"}, &tgbotapi.Chat{ID: 2})
	data.AddUser(&tgbotapi.User{ID: 3, UserName: "user3"}, &tgbotapi.Chat{ID: 3})
	data.AddUser(&tgbotapi.User{ID: 4, UserName: "user4"}, &tgbotapi.Chat{ID: 4})
	data.AddUser(&tgbotapi.User{ID: 5, UserName: "user5"}, &tgbotapi.Chat{ID: 5})
	data.AddUser(&tgbotapi.User{ID: 6, UserName: "user6"}, &tgbotapi.Chat{ID: 6})
	data.AddUser(&tgbotapi.User{ID: 7, UserName: "user7"}, &tgbotapi.Chat{ID: 7})
	data.AddUser(&tgbotapi.User{ID: 8, UserName: "user8"}, &tgbotapi.Chat{ID: 8})
	data.AddUser(&tgbotapi.User{ID: 9, UserName: "user9"}, &tgbotapi.Chat{ID: 9})
	data.AddUser(&tgbotapi.User{ID: 10, UserName: "user10"}, &tgbotapi.Chat{ID: 10})
	data.AddUser(&tgbotapi.User{ID: 11, UserName: "user11"}, &tgbotapi.Chat{ID: 11})
	data.AddUser(&tgbotapi.User{ID: 12, UserName: "user12"}, &tgbotapi.Chat{ID: 12})
	data.AddUser(&tgbotapi.User{ID: 13, UserName: "user13"}, &tgbotapi.Chat{ID: 13})


	client := data.clients["1"]

	room := data.CreateRoom(client)
	room.AddClient(data.clients["2"])
	room.AddClient(data.clients["3"])
	room.AddClient(data.clients["4"])
	room.AddClient(data.clients["5"])
	room.AddClient(data.clients["6"])
	room.AddClient(data.clients["7"])
	room.AddClient(data.clients["8"])
	room.AddClient(data.clients["9"])
	room.AddClient(data.clients["10"])
	room.AddClient(data.clients["11"])
	room.AddClient(data.clients["12"])
	room.AddClient(data.clients["13"])

	return data
}
