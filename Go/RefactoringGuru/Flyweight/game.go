package main

type Game struct {
	players []*Player
}

func NewGame() *Game {
	return &Game{players: make([]*Player, 0)}
}

func (g *Game) AddTerrorist() error {
	player, err := NewPlayer("Terrorist", TerroristDressType)
	if err != nil {
		return err
	}

	g.players = append(g.players, player)
	return nil
}

func (g *Game) AddCounterTerrorist() error {
	player, err := NewPlayer("CounterTerrorist", CounterTerroristDressType)
	if err != nil {
		return err
	}

	g.players = append(g.players, player)
	return nil
}