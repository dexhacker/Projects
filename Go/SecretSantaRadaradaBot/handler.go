package main

import (
	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"
	"log"
	"strconv"
)

type Handler struct {
	message      *tgbotapi.Message
	bot          *tgbotapi.BotAPI
	replyMessage string
	data         *Data
}

func NewHandler(message *tgbotapi.Message, bot *tgbotapi.BotAPI, data *Data) *Handler {
	return &Handler{message: message, bot: bot, data: data}
}

func (h *Handler) LogMessage() {
	name := ""
	if h.message.From.UserName == "" {
		name = strconv.Itoa(h.message.From.ID)
	} else {
		name = h.message.From.UserName
	}
	log.Printf("[%s] %s", name, h.message.Text)
}

func (h *Handler) Handle() {
	if h.message.Text == "/start" {
		h.replyMessage = NewHello(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/add_name" {
		h.replyMessage = NewAddName(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/edit_name" {
		h.replyMessage = NewEditName(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/show_name" {
		h.replyMessage = NewShowName(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/create_room" {
		h.replyMessage = NewCreateRoom(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/enter_to_room" {
		h.replyMessage = NewEnterToRoom(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/leave_room" {
		h.replyMessage = NewLeaveRoom(h.message, h.data, h.bot).GetReplyMessage()
		return
	}
	if h.message.Text == "/user_list" {
		h.replyMessage = NewUserList(h.message, h.data).GetReplyMessage()
		return
	}
	if h.message.Text == "/run" {
		h.replyMessage = NewRun(h.message, h.data, h.bot).GetReplyMessage()
		return
	}
	h.replyMessage = NewStatusReply(h.message, h.data, h.bot).GetReplyMessage()
}

func (h *Handler) SendReply() {
	h.data.PrintData()
	msg := tgbotapi.NewMessage(h.message.Chat.ID, h.replyMessage)
	msg.ReplyToMessageID = h.message.MessageID

	_, err := h.bot.Send(msg)
	if err != nil {
		log.Fatal(err.Error())
	}
}
