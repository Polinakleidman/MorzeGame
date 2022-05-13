#pragma once
#include "AlphabetWindow.h"

void Alphabet::render(sf::Window& Window){
    Window.create(sf::VideoMode(1200, 800), "Recall alphabet");
}

Alphabet::Alphabet() {
    factory = new MorzeFactory();
    std::vector<Button*> big_buttons = factory->create_all_transport_buttons();
    MenuButton = big_buttons[0];
    AlphabetButton =big_buttons[1];
    decorate_big_button(MenuButton, L"Вернуться\nк меню", 30, {100, 200, 40, 230},sf::Color::Blue, 480, 650,
                        240, 100);
    decorate_photo_button(AlphabetButton);
    AlphabetButton->colorChange = false;

}
