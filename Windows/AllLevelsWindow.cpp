#pragma once
#include "AllLevelsWindow.h"

void AllLevels::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Levels");
}

AllLevels::AllLevels(){
    factory = new LevelListFactory();
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    LevelButtons = factory->create_all_tolevellist_buttons(15);
    MenuButton = big_buttons[0];
    decorate_big_button(MenuButton, L"Вернуться\nк меню", 30, {0, 0, 139, 230}, sf::Color::Green, 480, 650,
                        240, 100);
    for(int i =0;i<15;++i){
        decorate_to_level_button(LevelButtons[i], i);
        LevelButtons[i]->setComplexity(i/5);
        LevelButtons[i]->setNumberOfLevel(i%5);
    }
}