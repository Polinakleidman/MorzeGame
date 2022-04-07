#include "Windows.h"
#include "SFML/graphics.hpp"

void Menu::render(sf::Window& Window) {
   Window.create(sf::VideoMode(700, 700), "Menu");
}

Menu::Menu() {
    WatchMorzeButton = Button();
    //WatchMorzeButton.set_all("../arial.ttf", "Открыть\n азбуку\n Морзе", 16,
      //                  "../button.png", middle, middle, sf::Color::Blue, 200, 200,
        //                40, 40);
    factory.CreateMorzeButton(WatchMorzeButton);
    //ToLevelListButton = Button();
    //factory.CreateToLevelListButton(ToLevelListButton);

}
