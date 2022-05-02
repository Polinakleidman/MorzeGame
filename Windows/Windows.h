#pragma once
#include "../Buttons.h"
#include "../Label.h"
#include <vector>
#include <string>

class Renderable{
protected:
     virtual void render(sf::Window& window) = 0;
     void decorate_big_button(Button*, std::wstring, int, sf::Color, sf::Color, float, float, float, float);
     void decorate_label(Label*, std::wstring, int, sf::Color, float, float, float, float);
     void decorate_to_level_button(Button*, int);
     void decorate_label_level(Label*, int, int);
     void decorate_photo_button(Button*);
};

