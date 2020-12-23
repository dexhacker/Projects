package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"log"
	"math/rand"
	"strconv"
)

type Run struct {
	message *tgbotapi.Message
	data    *Data
	bot     BotSender
}

func NewRun(message *tgbotapi.Message, data *Data, bot BotSender) *Run {
	return &Run{message: message, data: data, bot: bot}
}

func (r *Run) GetReplyMessage() string {
	id := r.message.From.ID
	client := r.data.clients[strconv.Itoa(id)]
	if client == nil {
		return "Пользователь не найден"
	}
	if client.GetCurrentRoom() == nil {
		return "Вы состоите не в какой комнате"
	}
	if client.GetCurrentRoom().IsDone() {
		return "Распределение Тайных Сант уже произошло!"
	}
	if client.GetCurrentRoom().GetOwner().GetUserName() != client.GetUserName() {
		return "Вы не являетесь админом комнаты!"
	}
	if len(client.GetCurrentRoom().GetClients()) < 2 {
		return "Количество участников должно быть больше 2-х человек"
	}
	client.GetCurrentRoom().SetDone()
	r.shuffleClients(client.GetCurrentRoom())
	return "Распределение завершено!"
}

func (r *Run) shuffleClients(room *Room) {
	hasSantaClients := make([]*Client, 0)
	for _, client := range room.GetClients() {
		notHasSantaClients := getNotHasSantaClients(room.GetClients(), append(hasSantaClients, client))
		targetClient := notHasSantaClients[rand.Intn(len(notHasSantaClients))]
		r.sendMessage(client, targetClient)
		client.SetCurrentRoom(nil)
		hasSantaClients = append(hasSantaClients, targetClient)
	}
}

func (r *Run) sendMessage(client *Client, targetClient *Client)  {
	message := fmt.Sprintf("Вы тайный санта для: %v", targetClient.GetRealName())
	msg := tgbotapi.NewMessage(client.GetChat().ID, message)
	_, err := r.bot.Send(msg)
	if err != nil {
		log.Fatalf("Error (sendMessage): %v", err.Error())
	}
}

func getNotHasSantaClients(allClients []*Client, hasSanta []*Client) []*Client {
	newSlice := make([]*Client, 0)
	for _, client := range allClients {
		has := false
		for _, hasSantaClient := range hasSanta {
			if client.GetUserName() == hasSantaClient.GetUserName() {
				has = true
			}
		}
		if !has {
			newSlice = append(newSlice, client)
		}
	}
	return newSlice
}
