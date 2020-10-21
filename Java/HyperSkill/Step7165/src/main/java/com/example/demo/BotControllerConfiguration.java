package com.example.demo;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class BotControllerConfiguration {


    @Bean
    public Message getMessage() {
        Message message = new Message();
        return message;
    }
}
