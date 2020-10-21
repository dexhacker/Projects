package com.example.demo;

public class AirportInfo {
    private String name;
    private String shortName;
    private String globalName;

    public AirportInfo(String name, String shortName, String globalName) {
        this.name = name;
        this.shortName = shortName;
        this.globalName = globalName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getShortName() {
        return shortName;
    }

    public void setShortName(String shortName) {
        this.shortName = shortName;
    }

    public String getGlobalName() {
        return globalName;
    }

    public void setGlobalName(String globalName) {
        this.globalName = globalName;
    }
}
