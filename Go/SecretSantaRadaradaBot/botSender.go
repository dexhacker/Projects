package main

import tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api"

type BotSender interface {
	Send(tgbotapi.Chattable) (tgbotapi.Message, error)
}
