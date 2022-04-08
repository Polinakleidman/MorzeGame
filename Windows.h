#pragma once
#include "Buttons.h"
#include "Factories.h"
#include <vector>
#include <string>

class Renderable{
private:
    void render(sf::Window& window);
};

class Menu: public Renderable{
public:
    MenuFactory factory;
public:
    Button WatchMorzeButton;
    Button ToLevelListButton;
    sf::RenderWindow window;
    Label Label0;
    Label LabelMorze;
public:
    Menu();
    void render(sf::Window& Window);
};

class Alphabet: public Renderable{
private:
    Factory factory;
public:
    Button MenuButton;
public:
    void render(sf::Window& window);
};

class AllLevels: public Renderable{
private:
    Factory factory;
public:
    std::vector<Button> LevelButtons;
    Button MenuButton;
public:
    void render(sf::Window& window);
};

class GameProcess: public Renderable{
private:
    Factory factory;
public:
    Button CheckButton;
    Button ToLevelListButton;
    std::vector<Button> Phrase;
public:
    void render(sf::Window& window);
};


class GameChecked: public Renderable{
private:
    Factory factory;
public:
    int level;
    int complexity;
    Button AgainButton;
    Button NextButton;
    Button ToLevelListButton;
public:
    void render(sf::Window& window);
};