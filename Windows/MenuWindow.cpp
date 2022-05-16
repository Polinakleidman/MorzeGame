#pragma once
#include "MenuWindow.h"

void Menu::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Menu");
}

Menu::Menu() {
    factory = new MenuFactory();
    std::vector<Button*> big_buttons = factory->create_all_transport_buttons();
    std::vector<Label*> labels = factory->create_all_labels();
    ToLevelListButton = big_buttons[0];
    WatchMorzeButton = big_buttons[1];
    Label0 = labels[0];
    LabelMorze = labels[1];
    decorate_big_button(ToLevelListButton, L"Выбор\nУровней", 30, {0, 0, 139, 230}, sf::Color::Yellow, 800, 550,
                        250, 150);
    decorate_big_button(WatchMorzeButton, L"Открыть\nазбуку\nМорзе", 30, sf::Color::Yellow,
                        sf::Color::Magenta, 120, 550,
                        250, 150);
    decorate_label(LabelMorze, L"-- --- .-. --.. .   --. .- -. .", 100, sf::Color{0x170603ff},
                   130, 300,
                   800, 200);
    decorate_label(Label0, L"Morze Game", 100, sf::Color{0x240803ff},
                   300, 150,
                   800, 200);
}
