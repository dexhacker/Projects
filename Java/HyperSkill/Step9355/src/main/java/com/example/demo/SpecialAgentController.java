package com.example.demo;

import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import javax.validation.constraints.Min;

@RestController
@Validated
public class SpecialAgentController {

    @GetMapping("/agents/{id}")
    ResponseEntity<String> validateAgentPathVariable(
            @PathVariable("id") @Min(1) int id) {
        return ResponseEntity.ok("Agent id is valid.");
    }

    @PostMapping("/agent")
    public ResponseEntity<String> validate(@Valid @RequestBody SpecialAgent agent) {
        return ResponseEntity.ok("Agent info is valid.");
    }
}
