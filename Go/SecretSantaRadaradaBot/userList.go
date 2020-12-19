package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type UserList struct {
	message *tgbotapi.Message
	data    *Data
}

func NewUserList(message *tgbotapi.Message, data *Data) *UserList {
	return &UserList{message: message, data: data}
}

func (h *UserList) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetCurrentRoom() == nil {
		return "Вы состоите не в какой комнате"
	}

	message := "Участники:\n"
	for index, clientItem := range client.GetCurrentRoom().GetClients() {
		message += fmt.Sprintf("%v) %v\n", index + 1, clientItem.GetRealName())
	}
	return message
}
