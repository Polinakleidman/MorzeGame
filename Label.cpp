#pragma once
#include "Label.h"

Label::Label(const std::string str)
{
    font.loadFromFile("../arialbd.ttf");
//    text.setString(str);
//    text.setFillColor({0, 255, 0, 50});
//    text.setCharacterSize(50);
}


void Label::draw(sf::RenderWindow &window)
{
    window.draw(text);
}


void Label::setAll(const std::wstring str, int text_size, sf::Color TextColor,
                   float positionX, float positionY,
                   float sizeX, float sizeY)
{
    sf::Text text0(str, font, text_size);
    text0.setFillColor(TextColor);
    text0.setPosition(positionX, positionY);
    text = text0;
}