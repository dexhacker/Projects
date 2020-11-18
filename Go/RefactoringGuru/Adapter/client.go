package main

import "fmt"

type Client struct {
}

func NewClient() *Client {
	return &Client{}
}

func (c *Client) insertLightningConnectorIntoComputer(com Computer) {
	fmt.Println("Client inserts Lightning connector into computer.")
	com.insertIntoLightningPort()
}
