package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"log"
	"strconv"
)

type StatusReply struct {
	message *tgbotapi.Message
	data    *Data
	bot     *tgbotapi.BotAPI
}

func NewStatusReply(message *tgbotapi.Message, data *Data, bot *tgbotapi.BotAPI) *StatusReply {
	return &StatusReply{message: message, data: data, bot: bot}
}

func (h *StatusReply) GetReplyMessage() string {
	id := h.message.From.ID
	client := h.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.status == "inserting name" {
		client.SetRealName(h.message.Text)
		client.SetStatus("")
		return "Вы успешно добавили имя"
	}
	if client.status == "edit name" {
		client.SetRealName(h.message.Text)
		client.SetStatus("")
		return "Вы успешно изменили имя"
	}
	if client.status == "find room" {
		id, err := strconv.Atoi(h.message.Text)
		if err != nil {
			return "Неверно введен номер комнаты!"
		}
		room := h.data.FindRoom(id)
		if room == nil {
			return "Данной комнаты не существует!"
		}
		client.SetCurrentRoom(room)
		h.notifyClients(room, client)
		room.AddClient(client)
		client.SetStatus("")
		return "Вы успешно вошли в комнату"
	}
	return "Команда не найдена"
}

func (h *StatusReply) notifyClients(room *Room, client *Client) {
	message := fmt.Sprintf("Зашел пользователь: %v", client.GetRealName())
	for _, clientItem := range room.GetClients() {
		h.sendMessage(clientItem, message)
	}
}

func (h *StatusReply) sendMessage(client *Client, message string) {
	msg := tgbotapi.NewMessage(client.GetChat().ID, message)
	_, err := h.bot.Send(msg)
	if err != nil {
		log.Fatal(err.Error())
	}
}
