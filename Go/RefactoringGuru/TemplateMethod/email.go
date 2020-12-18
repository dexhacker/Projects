package main

import "fmt"

type Email struct {
	Otp
}

func NewEmail() *Email {
	return &Email{}
}

func (s *Email) GenerateRandomOtp(length int) string {
	randomOtp := "5678"
	fmt.Printf("EMAIL: generating random otp %s\n\n", randomOtp)
	return randomOtp
}

func (s *Email) SaveOptCache(otp string) {
	fmt.Printf("EMAIL: saving otp: %s to cache\n", otp)
}

func (s *Email) GetMessage(otp string) string {
	return "EMAIL OTP for login is " + otp
}

func (s *Email) SendNotification(message string) error {
	fmt.Printf("EMAIL: sending sms: %s\n", message)
	return nil
}

func (s *Email) PublishMetric() {
	fmt.Printf("EMAIL: publishing metrics\n")
}

