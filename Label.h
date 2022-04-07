#include "SFML/Graphics.hpp"
#include <string>
#include <cfloat>

class Label {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape rectangle;
    sf::Texture buttonTexture;
    sf::Vector2f localTextPosition = {0, 0};
    float maxLengthText = FLT_MAX;


public:
    Label(const std::string str = "");
    void draw(sf::RenderWindow &window);
    void setAll(const std::string str, int text_size, sf::Color TextColor,
                std::string texture_file,sf::Color FillColor, float positionX, float positionY,
                float sizeX, float sizeY);
};