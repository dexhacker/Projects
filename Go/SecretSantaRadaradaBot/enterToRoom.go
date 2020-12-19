package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type EnterToRoom struct {
	message *tgbotapi.Message
	data    *Data
}

func NewEnterToRoom(message *tgbotapi.Message, data *Data) *EnterToRoom {
	return &EnterToRoom{message: message, data: data}
}

func (h *EnterToRoom) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetCurrentRoom() != nil {
		return fmt.Sprintf("Вы уже находитесь в комнате: %v", client.GetCurrentRoom().GetId())
	}
	client.SetStatus("find room")
	return "Введите номер команаты"
}
