#include <iostream>
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <string>
#include <windows.h>
#include <float.h>
#include <vector>

class LetterButton{
protected:
    sf::RectangleShape object;//сам квадратик
    sf::Texture texture;
    sf ::Text letter;//получаемая буква на кнопке с клавиатуры
    sf::Text appropriateLetter;
    sf::Vector2f localTextPosition = {0, 0};//расположение текста на кнопке
    bool isInsideObject = true;//курсор внутри кнопки
    sf::RenderWindow *window = 0;//окно в котором рисуем кнопку
    bool isEmpty;
    bool isChecked;
public:
    LetterButton();
    void draw(sf::RenderWindow &window);
    bool isClicked();
    bool is_correct();
    bool isCursorInsideBox();
    void writeLetter(sf::Text letter);
    void ChangeColor(sf::Text letter, sf::Text appropriateLetter, bool isChecked);
    void setTexture(sf ::Texture texture);
    void setSize(sf ::Vector2f size);
    void setPosition(sf ::Vector2f position);
};