#pragma once
#include "Windows.h"
#include "../Factories/MorzeFactory.h"

class Alphabet: public Renderable{
private:
    Factory* factory;
public:
    Button* MenuButton;
    Button* AlphabetButton;
public:
    Alphabet();
    void render(sf::Window& window) override;
};