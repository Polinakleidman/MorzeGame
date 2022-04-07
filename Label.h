#include "SFML/Graphics.hpp"
#include <string>

class Label {
private:
    sf::Text text;
    sf::Font font;

public:
    Label(const std::string str = "");
    void draw(sf::RenderWindow &window);
    void setString(const std::string str);
};