package main

type Application struct {
}

func NewApplication() *Application {
	return &Application{}
}

func (a *Application) HandleRequest(url, method string) (int, string) {
	if url == "/app/status" && method == "GET" {
		return 200, "OK"
	}

	if url == "/create/user" && method == "POST" {
		return 201, "Created"
	}

	return 404, "Not found"
}
