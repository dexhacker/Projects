.PHONY: build
build:
	go build -v ./cmd/server

.PHONY: migrate
migrate:
	migrate -path migrations -database "postgres://localhost/example_postgres?sslmode=disable&user=postgres&password=qwerty" up

.PHONY: rollback
rollback:
	migrate -path migrations -database "postgres://localhost/example_postgres?sslmode=disable&user=postgres&password=qwerty" down


.DEFAULT_GOAL := build