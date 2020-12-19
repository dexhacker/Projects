package main

import (
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type EditName struct {
	message *tgbotapi.Message
	data    *Data
}

func NewEditName(message *tgbotapi.Message, data *Data) *EditName {
	return &EditName{message: message, data: data}
}

func (h *EditName) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	client.SetStatus("edit name")
	return "Введите новое имя:"
}
