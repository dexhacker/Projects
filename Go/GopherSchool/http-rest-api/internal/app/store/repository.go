package store

import "github.com/Projects/Go/GopherSchool/http-rest-api/internal/app/model"

type UserRepository interface {
    Create(user *model.User) error
    FindByEmail(string) (*model.User, error)
    Find(int) (*model.User, error)
}
