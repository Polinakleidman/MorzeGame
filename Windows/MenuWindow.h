#pragma once
#include "Windows.h"
#include "../Factories/MenuFactory.h"

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