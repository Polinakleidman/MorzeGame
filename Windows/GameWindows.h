#pragma once
#include "Windows.h"
#include "../Factories/GameProcessFactory.h"
#include "../Factories/GameCheckedFactory.h"

class GameProcess: public Renderable{
private:
    Factory* factory;
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