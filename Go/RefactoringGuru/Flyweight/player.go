package main

type Player struct {
	dress      Dress
	playerType string
	lat        int
	long       int
}

func NewPlayer(playerType, dressType string) (*Player, error) {
	dress, err := GetDressFactorySingleInstance().getDressByType(dressType)
	if err != nil {
		return nil, err
	}

	player := &Player{
		dress:      dress,
		playerType: playerType,
	}
	return player, nil
}

func (p *Player) NewLocation(lat, long int) {
	p.lat = lat
	p.long = long
}
