#include "Label.h"

Label::Label(const std::string str)
{
    font.loadFromFile("../arial.ttf");
    text.setString(str);
    text.setFillColor({255, 0, 0, 50});
    text.setCharacterSize(50);
}


void Label::draw(sf::RenderWindow &window)
{
    window.draw(text);
}


void Label::setString(const std::string str)
{
    text.setString(str);
}