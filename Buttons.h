#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <cfloat>

enum PositionState {
    left,
    middle,
    right,
    down,
    top
};

class Button{
public:
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
    sf::Font font;
    bool colorChange = true;

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
    void setFillColor(sf::Color);
    void set_all(std::wstring Text, int text_size, sf::Color TextColor,
                 std::string texture_file, PositionState textPosX, PositionState textPosY,
                 sf::Color FillColor, float positionX, float positionY,
                 float sizeX, float sizeY);
    sf::Vector2f getScale();
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    virtual int getComlexity() const;
    virtual int getNumberOfLevel() const;
    virtual void setComplexity(int);
    virtual void setNumberOfLevel(int);
    virtual bool is_correct() const;
    virtual void setApproriateLetter(std::wstring);
    virtual void writeLetter(std::wstring);
    virtual void ChangeColor();
    virtual void set_letter(std::wstring);
    virtual std::wstring getLetter();
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
    ToLevelButton();
    int getComlexity() const override;
    int getNumberOfLevel() const override;
    void setComplexity(int) override;
    void setNumberOfLevel(int) override;
};

class LetterButton: public Button{
protected:
    std::wstring letter = L" ";
    std::wstring appropriateLetter = L" ";
    bool isEmpty = true;
public:
    explicit LetterButton();
    bool is_correct() const override;
    void setApproriateLetter(std::wstring) override;
    void writeLetter(std::wstring) override;
    void ChangeColor() override;
    void set_letter(std::wstring) override;
    std::wstring getLetter() override;
};



