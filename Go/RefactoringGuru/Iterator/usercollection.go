package main

type UserCollection struct {
	users []*User
}

func NewUserCollection(users []*User) *UserCollection {
	return &UserCollection{users: users}
}

func (u *UserCollection) CreateIterator() Iterator {
	return NewUserIterator(u.users)
}
