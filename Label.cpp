#include "Label.h"

Label::Label(const std::string str)
{
    rectangle.setSize({700, 300});
    font.loadFromFile("../arialbd.ttf");
//    text.setString(str);
//    text.setFillColor({0, 255, 0, 50});
//    text.setCharacterSize(50);
}


void Label::draw(sf::RenderWindow &window)
{
    window.draw(rectangle);
    window.draw(text);
}


void Label::setAll(const std::string str, int text_size, sf::Color TextColor,
                   std::string texture_file, sf::Color FillColor, float positionX, float positionY,
                   float sizeX, float sizeY)
{
    rectangle.setFillColor({255, 255, 255});
    sf::Text text0(str, font, text_size);
    text0.setFillColor(TextColor);
    text0.setPosition(positionX, positionY);
    text = text0;
}