package com.example.demo;

import org.springframework.stereotype.Component;

@Component
public class GreetingMessage {
    public GreetingMessage() {}

    public String hello() {
        return "Hello!!!";
    }
}
