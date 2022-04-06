#include "Buttons.h"
#include "Factories.h"
#include <vector>
#include <string>

class Renderable{
private:
    sf::RenderWindow& render();
};

class Menu: public Renderable{
private:
    Factory factory;
public:
    Button WatchMorzeButton;
    Button ToLevelListButton;
    sf::RenderWindow window;
public:
    sf::RenderWindow& render();
};

class Alphabet: public Renderable{
private:
    Factory factory;
public:
    Button MenuButton;
public:
    sf::RenderWindow& render();
};

class AllLevels: public Renderable{
private:
    Factory factory;
public:
    std::vector<Button> LevelButtons;
    Button MenuButton;
public:
    sf::RenderWindow& render();
};

class GameProcess: public Renderable{
private:
    Factory factory;
public:
    Button CheckButton;
    Button ToLevelListButton;
    std::vector<Button> Phrase;
public:
    sf::RenderWindow& render();
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
    sf::RenderWindow& render();
};