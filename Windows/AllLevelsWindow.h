#pragma once
#include "Windows.h"
#include "../Factories/LevelListFactory.h"

class AllLevels: public Renderable{
private:
    Factory* factory;
public:
    std::vector<ToLevelButton*> LevelButtons;
    Button* MenuButton;
public:
    AllLevels();
    void render(sf::Window& window) override;
};