package main

type OptGenerator interface {
	GenerateRandomOtp(int) string
	SaveOptCache(string)
	GetMessage(string) string
	SendNotification(string) error
	PublishMetric()
}
