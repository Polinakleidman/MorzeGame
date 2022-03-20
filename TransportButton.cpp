#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <float.h>
#include <vector>
#define ShapeWatchMorze RectangleShape
#define ShapeBackToMenu RectangleShape
#define ShapeToLevelList RectangleShape
#define ShapeToLevel CircleShape
#define ShapeCheck CircleShape
#define ShapeNextLevel CircleShape
#define ShapeAgain CircleShape
//пока кнопки перехода только прямоугольные и круглые, в дальнейшем может быть расширение на другие формы
//поэтому используем паттерн prototype

class TransportButton{
protected:
    //sf::Shape object(расширение на прямоугольник и круг ниже) встроенный класс SFML в нем хранится все об этой фигуре(цвет, расположение, размер)
    sf ::Text text;//текст на кнопке
    sf::Vector2f localTextPosition = {0, 0};//расположение текста на кнопке
    bool isInsideObject = true;//курсор внутри кнопки
    sf::RenderWindow *window = 0;//окно в котором рисуем кнопку
    std::string NextWindow; //куда переходить

public:
    TransportButton();
    void setTexture(sf ::Texture texture);
    void setWindow(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    bool isClicked();
    bool isCursorInsideBox();
    void setSize(sf ::Vector2f size);
    void setPosition(sf ::Vector2f position);
    void setText(sf::Text text);
};

class WatchMorzeButton: public TransportButton{
protected:
    sf:: ShapeWatchMorze object;
};
class BackToMenuButton: public TransportButton{
protected:
    sf:: ShapeBackToMenu object;
};
class ToLevelListButton: public TransportButton{
protected:
    sf:: ShapeToLevelList object;
};

class ToLevelButton: public TransportButton{
protected:
    sf::ShapeToLevel object;
    int Complexity{};
    int numberOfLevel{};
public:
    int getComlexity(){
        return Complexity;
    }
    int getNumberOfLevel(){
        return numberOfLevel;
    }
};
class CheckButton: public TransportButton{
protected:
    sf::ShapeCheck object;
};
class NextLevelButton: public TransportButton{
protected:
    sf::ShapeNextLevel object;
};
class AgainButton: public TransportButton{
protected:
    sf::ShapeAgain object;
};



