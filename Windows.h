#pragma once
#include "Buttons.h"
#include "Factories.h"
#include <vector>
#include <string>

class Renderable{
private:
     virtual void render(sf::Window& window) = 0;
};

class Menu: public Renderable{
public:
    Factory* factory;
public:
    Button* WatchMorzeButton;
    Button* ToLevelListButton;
    sf::RenderWindow window;
    Label* Label0;
    Label* LabelMorze;
public:
    Menu();
    void render(sf::Window& Window) override;
};

class Alphabet: public Renderable{
private:
    MorzeFactory* factory;
public:
    Button* MenuButton;
    Button* AlphabetButton;
public:
    Alphabet();
    void render(sf::Window& window) override;
};

class AllLevels: public Renderable{
private:
    LevelListFactory* factory;
public:
    std::vector<ToLevelButton*> LevelButtons;
    Button* MenuButton;
public:
    AllLevels();
    void render(sf::Window& window) override;
};

class GameProcess: public Renderable{
private:
    GameProcessFactory* factory;
public:
    int level;
    int complexity;
    sf::RenderWindow window;
    Label* Label0;
    Button* CheckButton;
    Button* ToLevelListButton;
    std::vector<LetterButton*> givenPhrase;
    std::vector<LetterButton*> enterPhrase;
public:
    GameProcess(int cur_level, int cur_complexity);
    void render(sf::Window& window) override;
};


class GameChecked: public Renderable{
private:
    GameCheckedFactory* factory;
public:
    int level;
    int complexity;
    Button* AgainButton;
    Button* NextButton;
    Button* ToLevelListButton;
    std::vector<LetterButton*> givenPhrase;
    std::vector<LetterButton*> enterPhrase;
    Label* Label0;
public:
    GameChecked(std::vector<std::wstring> players_answer, std::vector<bool> players_mistakes, int cur_level, int cur_complexity);
    void render(sf::Window& window) override;
};