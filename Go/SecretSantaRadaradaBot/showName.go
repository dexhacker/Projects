package main

import (
	"fmt"
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type ShowName struct {
	message *tgbotapi.Message
	data    *Data
}

func NewShowName(message *tgbotapi.Message, data *Data) *ShowName {
	return &ShowName{message: message, data: data}
}

func (h *ShowName) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	return fmt.Sprintf("Ваше имя: %v", client.GetRealName())
}
