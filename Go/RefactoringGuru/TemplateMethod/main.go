package main

func main() {
	smsOtp := NewSms()
	emailOtp := NewEmail()

	otp1 := NewOtp(smsOtp)
	otp1.GenerateAndSendOtp(4)

	otp2 := NewOtp(emailOtp)
	otp2.GenerateAndSendOtp(4)
}
