package main

import "fmt"

type Sms struct {
	Otp
}

func NewSms() *Sms {
	return &Sms{}
}

func (s *Sms) GenerateRandomOtp(length int) string {
	randomOtp := "1234"
	fmt.Printf("SMS: generating random otp %s\n\n", randomOtp)
	return randomOtp
}

func (s *Sms) SaveOptCache(otp string) {
	fmt.Printf("SMS: saving otp: %s to cache\n", otp)
}

func (s *Sms) GetMessage(otp string) string {
	return "SMS OTP for login is " + otp
}

func (s *Sms) SendNotification(message string) error {
	fmt.Printf("SMS: sending sms: %s\n", message)
	return nil
}

func (s *Sms) PublishMetric() {
	fmt.Printf("SMS: publishing metrics\n")
}
