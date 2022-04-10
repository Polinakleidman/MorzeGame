#pragma once
#include"Factories.h"

#include <iostream>


 void MenuFactory::CreateLabel(Label& label) {
    label.setAll(L"Morze Game", 100, sf::Color{0x240803ff},
                  300, 150,
                 800, 200);

}

void MenuFactory::CreateLabelMorze(Label &label) {
    label.setAll(L"-- --- .-. --.. .   --. .- -. .", 100, sf::Color{0x170603ff},
                 130, 300,
                 800, 200);
}

 void MenuFactory::CreateMorzeButton(Button& MorzeButton) {

    MorzeButton.set_all(L"Открыть\nазбуку\nМорзе", 35, sf::Color::Yellow,
                        "../button.png", middle, middle, sf::Color::Magenta, 120, 550,
                        250, 150);
}

void MenuFactory::CreateToLevelListButton(Button& LevelListButton){
    LevelListButton.set_all(L"Выбор\nУровней", 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, sf::Color::Yellow, 800, 550,
                        250, 150);
}

void LevelListFactory::CreateMenuButton(Button& MenuButton) {
    MenuButton.set_all(L"Вернуться\nк меню", 35, {0, 0, 139, 230},
                       "../button.png", middle, middle, sf::Color::Green, 480, 650,
                       240, 100);
}

void LevelListFactory::CreateToLevelButtons(ToLevelButton& button, int i) {
        std::wstring complexity = std::to_wstring(i/5+1);
        std::wstring level = std::to_wstring(i%5+1);
        complexity+= ' ';
        complexity+=level;
        button.set_all(complexity, 30, {0, 0, 139, 230}, "../button.png", middle, middle, sf::Color::Green,
                                160+(i%5)*170, 80+(i/5)*170, 150, 150);
        std::cout<<100+(i/5)*200<<" ";
}

void GameProcessFactory::CreateToLevelListButton(Button& ToLevelListButton) {
    ToLevelListButton.set_all(L"Вернуться\nк выбору\nуровней", 35, {0, 0, 139, 230},
                            "../button.png", middle, middle, sf::Color::Yellow, 120, 550,
                            250, 150);
}

void GameProcessFactory::CreateCheckButton(Button& CheckButton) {
    CheckButton.set_all(L"Проверить", 35, {0, 0, 139, 230},
                            "../button.png", middle, middle, sf::Color::Yellow, 830, 550,
                            250, 150);
}

void GameProcessFactory::CreateLabel(Label& label, int level, int complexity) {
    std::wstring lab;
    lab = L"Уровень " + std::to_wstring(complexity) + L"." + std::to_wstring(level);
    label.setAll(lab, 100, sf::Color{0x240803ff},
                 300, 100,
                 800, 200);
}

void GameProcessFactory::CreateLetterButton(Button& letter_button, int x, int y, std::wstring& letter) {
    letter_button.set_all(letter, 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, sf::Color::Yellow, x, y,
                        70, 70);
}

void GameCheckedFactory::CreateAgainButton(Button& againbutton) {
    againbutton.set_all(L"Заново", 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, sf::Color::Yellow, 120, 550,
                        250, 150);
}

void GameCheckedFactory::CreateNextLevelButton(Button& nextbutton) {
    nextbutton.set_all(L"Следующий\nуровень", 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, sf::Color::Yellow, 830, 550,
                        250, 150);
}

void GameCheckedFactory::CreateToLevelListButton(Button& tolevellistbutton) {
    tolevellistbutton.set_all(L"К выбору\nуровней", 35, {0, 0, 139, 230},
                        "../button.png", middle, middle, sf::Color::Yellow, 500, 550,
                        250, 150);
}

void::GameCheckedFactory::CreateLetterButton(Button& letter_button, int x, int y, std::wstring& letter){
    letter_button.set_all(letter, 35, {0, 0, 139, 230},
                          "../button.png", middle, middle, sf::Color::Yellow, x, y,
                          70, 70);
    letter_button.colorChange = false;
}

void GameCheckedFactory::CreateLabel(Label& label, int level, int complexity) {
    std::wstring lab;
    lab = L"Уровень " + std::to_wstring(complexity) + L"." + std::to_wstring(level);
    label.setAll(lab, 100, sf::Color{0x240803ff},
                 300, 100,
                 800, 200);
}
