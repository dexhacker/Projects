package main

func GetBuilder(builderType string) IBuilder {
    if builderType == "normal" {
        return NewNormalBuilder()
    }
    if builderType == "igloo" {
        return NewIglooBuilder()
    }
    return nil
}
