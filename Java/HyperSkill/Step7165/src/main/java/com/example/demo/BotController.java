package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@Component
@RestController
public class BotController {

    GreetingMessage greetingMessage;
    Message message;

    @Autowired
    public BotController(GreetingMessage greetingMessage, Message message) {
        this.greetingMessage = greetingMessage;
        this.message = message;
    }

    @PostMapping(value = "/greet", consumes = "application/json")
    public String greet(@RequestBody List<UserInfo> userInfoList) {
        return greetingMessage.hello() + " " + message.message();
    }
}
