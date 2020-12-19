package main

type Room struct {
	id      int
	owner   *Client
	clients []*Client
	isDone  bool
}

func NewRoom(index int, client *Client) *Room {
	clients := make([]*Client, 0)
	clients = append(clients, client)
	return &Room{id: index, owner: client, clients: clients}
}

func (r *Room) GetId() int {
	return r.id
}

func (r *Room) GetOwner() *Client {
	return r.owner
}

func (r *Room) GetClients() []*Client {
	return r.clients
}

func (r *Room) AddClient(client *Client) {
	r.clients = append(r.clients, client)
}

func (r *Room) RemoveClient(clientForRemove *Client) {
	newSlice := make([]*Client, 0)
	for _, client := range r.clients {
		if client.GetUserName() != clientForRemove.GetUserName() {
			newSlice = append(newSlice, client)
		}
	}
	r.clients = newSlice
}

func (r *Room) IsDone() bool {
	return r.isDone
}

func (r *Room) SetDone() {
	r.isDone = true
}
