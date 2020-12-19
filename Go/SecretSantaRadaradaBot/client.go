package main

import tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"

type Client struct {
	id          int
	userName    string
	status      string
	realName    string
	currentRoom *Room
	chat        *tgbotapi.Chat
}

func NewClient(userName string, chat *tgbotapi.Chat, id int) *Client {
	return &Client{userName: userName, status: "inserting name", chat: chat, id: id}
}

func (c *Client) GetID() int {
	return c.id
}

func (c *Client) GetUserName() string {
	return c.userName
}

func (c *Client) SetRealName(realName string) {
	c.realName = realName
}

func (c *Client) GetRealName() string {
	return c.realName
}

func (c *Client) SetStatus(status string) {
	c.status = status
}

func (c *Client) GetStatus() string {
	return c.status
}

func (c *Client) GetCurrentRoom() *Room {
	return c.currentRoom
}

func (c *Client) SetCurrentRoom(room *Room) {
	c.currentRoom = room
}

func (c *Client) GetChat() *tgbotapi.Chat {
	return c.chat
}
