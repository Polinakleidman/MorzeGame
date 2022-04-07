#pragma-once
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <float.h>
#include <vector>
#include "Buttons.h"
#include <iostream>


sf::Vector2f GetCursorPosition(sf::RenderWindow &window);

bool IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle);


sf::Vector2f GetCursorPosition(sf::RenderWindow &window) {
    sf::Vector2f cursorPosition;

    cursorPosition = (sf::Vector2f) sf::Mouse::getPosition(window);
    cursorPosition = window.mapPixelToCoords((sf::Vector2i) cursorPosition);

    return cursorPosition;
}


bool IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle) {
    sf::Vector2f position = rectangle->getPosition();
    sf::Vector2f size = rectangle->getSize();
    sf::Vector2f scale = rectangle->getScale();

    size = {size.x * scale.x, size.y * scale.y};

    if (cursorPosition.x >= position.x && cursorPosition.x <= position.x + size.x &&
        cursorPosition.y >= position.y && cursorPosition.y <= position.y + size.y) {
        return 1;
    }

    return 0;
}


sf::Vector2f Button::getScale(){
    return rectangle.getScale();
}

Button::Button() {
    rectangle.setSize({200, 100});
}

void Button::setTextHeight() {
    if (text.getString() == "") return;

    sf::Vector2f sizeRect = rectangle.getSize();

    sf::FloatRect textBounds = this->text.getLocalBounds();

    if (textBounds.height > sizeRect.y) {
        int sizeText = text.getCharacterSize();
        text.setCharacterSize(int(sizeText / textBounds.height * sizeRect.y - 5));
    }
}


void Button::draw(sf::RenderWindow &window) {
    this->window = &window;

    window.draw(rectangle);

    window.draw(text);

    isCursorInsideBox();
}


bool Button::isPressed() {
    if (window == NULL) return 0;

    sf::Vector2f cursorPosition = GetCursorPosition(*window);
    sf::Vector2f scale = rectangle.getScale();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!IsInsideRect(cursorPosition, &rectangle) && !isLeftButtonPressed) {
            isInsideRect = false;
        }

        isLeftButtonPressed = true;
    } else {
        isLeftButtonPressed = false;
        isInsideRect = true;

        return 0;
    }

    if (!isInsideRect) return 0;

    return 1;
}


void Button::isCursorInsideBox() {
    sf::Color color({0, 0, 0, 20});

    rectChoose.setFillColor(color);
    rectChoose.setSize(rectangle.getSize());
    rectChoose.setPosition(rectangle.getPosition());

    sf::Vector2f cursorPosition = GetCursorPosition(*window);

    if (IsInsideRect(cursorPosition, &rectangle)) {
        window->draw(rectChoose);
    }
}


void Button::setTexture(sf::Texture texture) {
    buttonTexture = texture;

    rectangle.setTexture(&buttonTexture);
}

void Button::setSize(sf::Vector2f size) {
    rectangle.setSize(size);

    if (text.getString() != "") {
        setTextHeight();
        setTextLength(maxLengthText);

        this->text.setPosition(getPosition() + localTextPosition);
    }
}

void Button::setPosition(sf::Vector2f position) {
    rectangle.setPosition(position);

    if (text.getString() != "") {
        text.setPosition(position + localTextPosition);
    }
}


void Button::setText(sf::Text text) {
    startText = text;

    this->text = text;

    setTextHeight();
    setTextLength(maxLengthText);

    this->text.setPosition(getPosition() + localTextPosition);
    this->text.setScale(getScale());
}


void Button::setTextPosition(PositionState posX, PositionState posY) {
    if (text.getString() == "") return;

    sf::Vector2f scaleRect = rectangle.getScale();
    sf::Vector2f sizeRect = rectangle.getSize();

    sizeRect = {sizeRect.x * scaleRect.x, sizeRect.y * scaleRect.y};

    sf::FloatRect textBounds = text.getLocalBounds();

    textBounds.width *= scaleRect.x;
    textBounds.height *= scaleRect.y;
    textBounds.left *= scaleRect.x;
    textBounds.top *= scaleRect.y;

    switch (posX) {
        case left:
            localTextPosition.x = 0;
            break;

        case middle:
            localTextPosition.x = (sizeRect.x - textBounds.width) / 2 - textBounds.left;
            break;

        case right:
            localTextPosition.x = sizeRect.x - textBounds.width - textBounds.left;
            break;
    }

    switch (posY) {
        case top:
            localTextPosition.y = 0;
            break;

        case middle:
            localTextPosition.y = (sizeRect.y - textBounds.height) / 2 - textBounds.top;
            break;

        case down:
            localTextPosition.y = sizeRect.y - textBounds.height - textBounds.top;
            break;
    }

    text.setPosition(getPosition() + localTextPosition);
}


void Button::setTextLength(float length) {
    if (text.getString() == "") return;

    std::string textStr = startText.getString();

    sf::FloatRect boundsText = text.getLocalBounds();
    sf::Vector2f scaleRect = rectangle.getScale();
    sf::Vector2f sizeRect = rectangle.getSize();

    if (length > sizeRect.x) {
        length = sizeRect.x;
    }

    if (boundsText.width <= length) {
        maxLengthText = boundsText.width;

        return;
    }

    maxLengthText = length;

    std::string newTextStr = "";
    float nowLength = 0;

    int lenStr = textStr.length();
    for (int i = 1; i <= lenStr; i++) {
        float letterWidth = text.findCharacterPos(i).x - text.findCharacterPos(i - 1).x;
        letterWidth /= scaleRect.x;

        nowLength += letterWidth;

        if (nowLength <= length) {
            newTextStr += textStr[i - 1];
        } else {
            break;
        }
    }

    text.setString(newTextStr);
}



sf::Vector2f Button::getPosition() {
    return rectangle.getPosition();
}


sf::Vector2f Button::getSize() {
    return rectangle.getSize();
}

LetterButton::LetterButton(char c){
    rectangle.setSize({100, 100});
    appropriateLetter = c;
    isEmpty = false;
}
bool LetterButton::is_correct() const {
    if (letter == appropriateLetter){
        return true;
    }
    return false;
}

void LetterButton::writeLetter(sf::Font& font) {
    char s;
    std::cin>>s;
    letter = s;
    sf::Text text0(s, font, 25);
    setText(text0);
    setTextPosition(middle, middle);
}

void LetterButton::ChangeColor(){
    if (is_correct()){
        rectangle.setFillColor({0, 255, 0, 200});
    }
    else{
        rectangle.setFillColor({255, 0, 0, 200});
    }
    setTextPosition(middle, middle);
}

TransportButton::TransportButton() {
    rectangle.setSize({100, 100});
}

ToLevelButton::ToLevelButton(int c, int n){
    rectangle.setSize({100, 100});
    Complexity = c;
    numberOfLevel = n;
};

int ToLevelButton::getComlexity() const{
    return Complexity;
}
int ToLevelButton::getNumberOfLevel() const{
    return numberOfLevel;
}
