.PHONY: build
build:
	go build -v ./cmd/apiserver

.PHONY: test
test:
	go test -v -race -timeout 30s ./...

.PHONY: migrate
migrate:
	migrate -path migrations -database "postgres://localhost/restapi_dev?sslmode=disable&user=postgres&password=qwerty" up

.PHONY: rollback
rollback:
	migrate -path migrations -database "postgres://localhost/restapi_dev?sslmode=disable&user=postgres&password=qwerty" down

.PHONY: migrate_test
migrate_test:
	migrate -path migrations -database "postgres://localhost/restapi_test?sslmode=disable&user=postgres&password=qwerty" up

.PHONY: rollback_test
rollback_test:
	migrate -path migrations -database "postgres://localhost/restapi_test?sslmode=disable&user=postgres&password=qwerty" down

.DEFAULT_GOAL := build
