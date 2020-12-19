package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

type CreateRoom struct {
	message *tgbotapi.Message
	data    *Data
}

func NewCreateRoom(message *tgbotapi.Message, data *Data) *CreateRoom {
	return &CreateRoom{message: message, data: data}
}

func (h *CreateRoom) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetCurrentRoom() != nil {
		return fmt.Sprintf("Вы уже находитесь в комнате: %v", client.GetCurrentRoom().GetId())
	}
	room := h.data.CreateRoom(client)
	return fmt.Sprintf("Комната созадана. Номер комнаты: %v", room.GetId())
}
