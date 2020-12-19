package main

import (
	"fmt"
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type AddName struct {
	message *tgbotapi.Message
	data    *Data
}

func NewAddName(message *tgbotapi.Message, data *Data) *AddName {
	return &AddName{message: message, data: data}
}

func (h *AddName) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetRealName() != "" {
		return fmt.Sprintf("У вас уже уставнолено имя: %v", client.GetRealName())
	}
	client.SetStatus("inserting name")
	return "Введите новое имя:"
}
