package main

import (
	"fmt"
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"strconv"
)

var rooms = make([]*Room, 0)
var clients = make(map[string]*Client)

type Data struct {
	rooms []*Room
	clients map[string]*Client
}

func NewData() *Data {
	return &Data{rooms: rooms, clients: clients}
}

func (d *Data) AddUser(user *tgbotapi.User, chat *tgbotapi.Chat) {
	id := strconv.Itoa(user.ID)
	d.clients[id] = NewClient(user.UserName, chat, user.ID)
}

func (d *Data) FindUser(user *tgbotapi.User) *Client {
	return d.clients[user.UserName]
}

func (d *Data) CreateRoom(client *Client) *Room {
	room := NewRoom(len(d.rooms) + 1, client)
	client.SetCurrentRoom(room)
	d.rooms = append(d.rooms, room)
	return room
}

func (d *Data) FindRoom(id int) *Room {
	for _, room := range d.rooms {
		if room.GetId() == id {
			return room
		}
	}
	return nil
}

func (d *Data) PrintData() {
	fmt.Println("Clients:")
	message := "ID: %v, USERNAME: %v: STATUS: %v, REAL_NAME: %v\n"
	for _, client := range d.clients {
		fmt.Printf(message, client.GetID(), client.GetUserName(), client.GetStatus(), client.GetRealName())
	}
	fmt.Println("Rooms:")
	message = "ID: %v, OWNER: %v, CLIENT_COUNT: %v\n"
	for _, room := range d.rooms {
		fmt.Printf(message, room.GetId(), room.GetOwner().GetUserName(), len(room.GetClients()))
	}
}
