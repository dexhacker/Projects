package main

type Otp struct {
	otpGenerator OptGenerator
}

func NewOtp(generator OptGenerator) *Otp {
	return &Otp{otpGenerator: generator}
}

func (o *Otp) GenerateAndSendOtp(otpLength int) error {
	otp := o.otpGenerator.GenerateRandomOtp(otpLength)
	o.otpGenerator.SaveOptCache(otp)
	message := o.otpGenerator.GetMessage(otp)
	err := o.otpGenerator.SendNotification(message)
	if err != nil {
		return err
	}
	o.otpGenerator.PublishMetric()
	return nil
}
