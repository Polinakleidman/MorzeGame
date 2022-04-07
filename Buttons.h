#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

enum PositionState {
    left,
    middle,
    right,
    down,
    top
};

class Button{
protected:
    sf::RectangleShape rectangle;
    sf::Texture buttonTexture;
    sf::RectangleShape rectChoose;
    sf::Text startText;
    sf::Text text;
    sf::Vector2f localTextPosition = {0, 0};
    bool isLeftButtonPressed = false;
    bool isInsideRect = true;
    sf::RenderWindow* window = 0;
    float maxLengthText = FLT_MAX;
    void setTextHeight();

public:
    Button();
    void setTexture(sf ::Texture texture);
    void draw(sf::RenderWindow& window);
    bool isPressed();
    void isCursorInsideBox();
    void setSize(sf ::Vector2f size);
    void setPosition(sf ::Vector2f position);
    void setText(sf::Text text);
    void setTextPosition(PositionState posX, PositionState posY);
    void setTextLength(float length);
    sf::Vector2f getScale();
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
};

class TransportButton : public Button {
protected:
    std::string NextWindow;
public:
    TransportButton();
};


class ToLevelButton: public TransportButton{
protected:
    int Complexity;
    int numberOfLevel;
public:
    ToLevelButton(int c, int n);
    int getComlexity() const;
    int getNumberOfLevel() const;
};

class LetterButton: public Button{
protected:
    char letter = ' ';
    char appropriateLetter;
    bool isEmpty = true;
public:
    explicit LetterButton(char c);
    bool is_correct() const;
    void writeLetter(sf::Font& font);
    void ChangeColor();
};



