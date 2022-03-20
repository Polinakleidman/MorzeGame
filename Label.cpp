#include "SFML/Graphics.hpp"
#include <string>

class Label {
private:
    sf::Text text;

public:
    Label(const std::string str = "");

    void draw(sf::RenderWindow &window);
    void setText(const std::string str);
};