package sqlstore_test

import (
    "github.com/Projects/Go/GopherSchool/http-rest-api/internal/app/model"
    "github.com/Projects/Go/GopherSchool/http-rest-api/internal/app/store"
    "github.com/Projects/Go/GopherSchool/http-rest-api/internal/app/store/sqlstore"
    "github.com/stretchr/testify/assert"
    "testing"
)

func TestUserRepository_Create(t *testing.T) {
    db, teardown := sqlstore.TestDB(t, databaseUrl)
    defer teardown("users")

    s := sqlstore.New(db)
    u := model.TestUser(t)

    assert.NoError(t, s.User().Create(u))
    assert.NotNil(t, u)
}

func TestUserRepository_Find(t *testing.T) {
    db, teardown := sqlstore.TestDB(t, databaseUrl)
    defer teardown("users")

    s := sqlstore.New(db)
    email := "user@example.com"
    _, err := s.User().Find(0)
    assert.EqualError(t, err, store.ErrRecordNotFound.Error())

    u := model.TestUser(t)
    u.Email = email
    err = s.User().Create(u)

    if err != nil {
        t.Fatal(err)
    }

    u, err = s.User().Find(u.ID)
    assert.NotNil(t, u)
}

func TestUserRepository_FindByEmail(t *testing.T) {
    db, teardown := sqlstore.TestDB(t, databaseUrl)
    defer teardown("users")

    s := sqlstore.New(db)
    email := "user@example.com"
    _, err := s.User().FindByEmail(email)
    assert.EqualError(t, err, store.ErrRecordNotFound.Error())

    u := model.TestUser(t)
    u.Email = email
    err = s.User().Create(u)

    if err != nil {
        t.Fatal(err)
    }

    u, err = s.User().FindByEmail(email)
    assert.NotNil(t, u)
}
