package main

import (
	"fmt"
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type Hello struct {
	message *tgbotapi.Message
	data    *Data
}

func NewHello(message *tgbotapi.Message, data *Data) *Hello {
	return &Hello{message: message, data: data}
}

func (h *Hello) GetReplyMessage() string {
	h.data.AddUser(h.message.From, h.message.Chat)
	message := "Привет, %v. Пожалуйста введи своё имя, по которому твои друзья тебя узнают"
	name := ""
	if h.message.From.UserName == "" {
		name = strconv.Itoa(h.message.From.ID)
	} else {
		name = h.message.From.UserName
	}
	return fmt.Sprintf(message, name)
}
