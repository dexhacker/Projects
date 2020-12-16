package main

import "fmt"

func main() {
	user1 := NewUser("a", 30)
	user2 := NewUser("b", 20)

	userCollection := NewUserCollection([]*User{user1, user2})

	iterator := userCollection.CreateIterator()

	for iterator.HasNext() {
		user := iterator.GetNext()
		fmt.Printf("User is %+v\n", user)
	}
}
