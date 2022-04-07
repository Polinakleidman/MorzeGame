#pragma once
#include"Factories.h"


 void MenuFactory::CreateLabel(Label& label) {
    label.setAll("Morze Game", 50, {139, 26, 26, 230},
                 "../button.png", {0, 245, 255, 120}, 300, 300,
                 250, 150);
}

 void MenuFactory::CreateMorzeButton(Button& MorzeButton) {

   MorzeButton.set_all(L"Открыть\nазбуку\nМорзе", 35, {139, 26, 26, 230},
                        "../button.png", middle, middle, {0, 245, 255, 120}, 120, 550,
                        250, 150);

//     sf::Vector2<float> size(200, 200);
//     MorzeButton.setSize(size);
//
//     sf::Vector2<float> position(200, 200);
//     MorzeButton.setPosition(position);
//
//     sf::Text goToMorze("G", MorzeButton.font, 50);
//     goToMorze.setFillColor({255, 0, 0, 100});
//     MorzeButton.setText(goToMorze);
//
//     sf::Texture MorzeTexture;
//     MorzeTexture.loadFromFile("../button.png");
//     MorzeButton.setTexture(MorzeTexture);
//
//     MorzeButton.setTextPosition(middle, middle);



}

void MenuFactory::CreateToLevelListButton(Button& LevelListButton){

    LevelListButton.set_all(L"Выбор\nУровней", 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, {161, 83, 143, }, 800, 550,
                        250, 150);
}

