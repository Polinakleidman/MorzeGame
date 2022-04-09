#pragma once
#include "Windows.h"
#include "SFML/graphics.hpp"
#include <iostream>

void Menu::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Menu");
}

void AllLevels::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Levels");
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

AllLevels::AllLevels(){
    MenuButton = Button();
    LevelButtons = std::vector<ToLevelButton>(15);
    factory.CreateMenuButton(MenuButton);
    for(int i =0;i<15;++i){
        factory.CreateToLevelButtons(LevelButtons[i], i);
        LevelButtons[i].setComplexity(i/5);
        LevelButtons[i].setNumberOfLevel(i%5);
    }
    std::cout<<LevelButtons.size();
    //factory.CreateToLevelButtons(levelButtons);
}
