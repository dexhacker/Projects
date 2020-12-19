package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"log"
	"strconv"
)

type LeaveRoom struct {
	message *tgbotapi.Message
	data    *Data
	bot     *tgbotapi.BotAPI
}

func NewLeaveRoom(message *tgbotapi.Message, data *Data, bot *tgbotapi.BotAPI) *LeaveRoom {
	return &LeaveRoom{message: message, data: data, bot: bot}
}

func (h *LeaveRoom) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetCurrentRoom() == nil {
		return "Вы не находитесь в комнате"
	}
	client.GetCurrentRoom().RemoveClient(client)
	h.notifyClients(client.GetCurrentRoom(), client)
	client.SetCurrentRoom(nil)
	return "Вы успешно покинули комнату"
}

func (h *LeaveRoom) notifyClients(room *Room, client *Client) {
	message := fmt.Sprintf("Вышел из комнаты пользователь: %v", client.GetRealName())
	for _, clientItem := range room.GetClients() {
		h.sendMessage(clientItem, message)
	}
}

func (h *LeaveRoom) sendMessage(client *Client, message string) {
	msg := tgbotapi.NewMessage(client.GetChat().ID, message)
	_, err := h.bot.Send(msg)
	if err != nil {
		log.Fatal(err.Error())
	}
}
