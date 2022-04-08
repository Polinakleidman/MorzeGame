#pragma once
#include "Windows.h"
#include "SFML/graphics.hpp"

void Menu::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Menu");
}

Menu::Menu() {
    WatchMorzeButton = Button();
    factory.CreateMorzeButton(WatchMorzeButton);
    ToLevelListButton = Button();
    factory.CreateToLevelListButton(ToLevelListButton);
    Label0 = Label();
    LabelMorze = Label();
    factory.CreateLabel(Label0);
    factory.CreateLabelMorze(LabelMorze);


}
