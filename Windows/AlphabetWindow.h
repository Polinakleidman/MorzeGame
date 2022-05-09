#pragma once
#include "Windows.h"
#include "../Factories/MorzeFactory.h"

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