package main

import (
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"log"
	"math/rand"
	"time"
)

type Connection struct {
	token string
	bot   *tgbotapi.BotAPI
	data  *Data
}

func NewConnection(token string) *Connection {
	return &Connection{token: token}
}

func (c *Connection) Connect() {
	bot, err := tgbotapi.NewBotAPI(c.token)
	if err != nil {
		log.Fatal(err.Error())
	}
	c.bot = bot
}

func (c *Connection) SetConf() {
	//c.bot.Debug = true
	c.data = NewData()
	rand.Seed(time.Now().Unix())
}

func (c *Connection) TestConnection() {
	log.Printf("Authorized on account %s", c.bot.Self.UserName)
}

func (c *Connection) StartListening() {
	u := tgbotapi.NewUpdate(0)
	updates, err := c.bot.GetUpdatesChan(u)
	if err != nil {
		log.Fatal(err.Error())
	}
	for update := range updates {
		if update.Message == nil { // ignore any non-Message Updates
			continue
		}

		handler := NewHandler(update.Message, c.bot, c.data)
		handler.LogMessage()
		handler.Handle()
		handler.SendReply()
	}
}
