#pragma once
#include "Windows.h"
#include "SFML/graphics.hpp"
#include <iostream>
#include <vector>
#include "Windows.h"
#include "SFML/graphics.hpp"
#include<string>
#include<vector>

void Renderable::decorate_big_button(Button* buttton, std::wstring Text, int text_size, sf::Color TextColor,
                                     sf::Color FillColor, float positionX, float positionY,
                                     float sizeX, float sizeY){
    buttton->set_all(Text, text_size, TextColor, "../button.png", middle, middle, FillColor, positionX, positionY, sizeX, sizeY);
}

void Renderable::decorate_label(Label* label, std::wstring str, int text_size, sf::Color TextColor,
                    float positionX, float positionY,
                    float sizeX, float sizeY){
    label->setAll(str, text_size, TextColor, positionX, positionY, sizeX, sizeY);
}

void Renderable::decorate_to_level_button(Button* button, int i){
    std::wstring complexity = std::to_wstring(i/5+1);
    std::wstring level = std::to_wstring(i%5+1);
    complexity+= ' ';
    complexity+=level;
    decorate_big_button(button, complexity, 30, {0, 0, 139, 230}, sf::Color::Green,
                        160+(i%5)*170, 80+(i/5)*170, 150, 150);
}

void Renderable::decorate_label_level(Label* label, int level, int complexity){
    std::wstring lab;
    lab = L"Уровень " + std::to_wstring(complexity) + L"." + std::to_wstring(level);
    decorate_label(label, lab, 100, sf::Color{0x240803ff},
                   300, 100,
                   800, 200);
}

void Renderable::decorate_photo_button(Button* AlphabetPhoto){
    sf::Texture texture;
    texture.loadFromFile("../Alphabet.jpg");
    AlphabetPhoto->setTexture(texture);
    AlphabetPhoto->setPosition({150, 70});
    AlphabetPhoto->setSize({900, 520});
}

void Menu::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Menu");
}
void AllLevels::render(sf::Window& Window) {
    Window.create(sf::VideoMode(1200, 800), "Levels");
}
void GameProcess::render(sf::Window &Window) {
    Window.create(sf::VideoMode(1200, 800), "Game is on");
}
void GameChecked::render(sf::Window &Window) {
    Window.create(sf::VideoMode(1200, 800), "Your answer has been checked");
}

void Alphabet::render(sf::Window& Window){
    Window.create(sf::VideoMode(1200, 800), "Recall alphabet");
}

Menu::Menu() {
    Factory* factory = new MenuFactory();
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    std::vector<Label*> labels = factory->create_all_labels();
    ToLevelListButton = big_buttons[0];
    WatchMorzeButton = big_buttons[1];
    Label0 = labels[0];
    LabelMorze = labels[1];
    decorate_big_button(ToLevelListButton, L"Выбор\nУровней", 35, {0, 0, 139, 230}, sf::Color::Yellow, 800, 550,
                        250, 150);
    decorate_big_button(WatchMorzeButton, L"Открыть\nазбуку\nМорзе", 35, sf::Color::Yellow,
                        sf::Color::Magenta, 120, 550,
                        250, 150);
    decorate_label(LabelMorze, L"-- --- .-. --.. .   --. .- -. .", 100, sf::Color{0x170603ff},
                   130, 300,
                   800, 200);
    decorate_label(Label0, L"Morze Game", 100, sf::Color{0x240803ff},
                   300, 150,
                   800, 200);
}

GameProcess::GameProcess(int cur_level, int cur_complexity) {
    Factory* factory = new GameProcessFactory();
    level = cur_level;
    complexity = cur_complexity;
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    std::vector<LetterButton*> lettersbut =  factory->create_all_letter_buttons(18);
    for(int i =0;i<9;++i){
        enterPhrase.push_back(lettersbut[i]);
        givenPhrase.push_back(lettersbut[i+9]);
    }
    std::vector<Label*> all_labels = factory->create_all_labels();
    ToLevelListButton = big_buttons[0];
    CheckButton = big_buttons[1];
    Label0 = all_labels[0];
    decorate_big_button(ToLevelListButton, L"Вернуться\nк выбору\nуровней", 35, {0, 0, 139, 230},
                        sf::Color::Yellow, 120, 550,
                        250, 150);
    decorate_big_button(CheckButton, L"Проверить", 35, {0, 0, 139, 230},
                        sf::Color::Yellow, 830, 550,
                        250, 150);
    decorate_label_level(Label0, level, complexity);
    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};
    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;

    for (int i = 0; i < givenPhrase.size(); ++i) {
        givenPhrase[i]->colorChange = false;
        givenPhrase[i]->setApproriateLetter(phrase[i]);
        decorate_big_button(givenPhrase[i], phrase[i], 35, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 270,
                            70, 70);
    }
    for (int i = 0; i < givenPhrase.size(); ++i) {
        std::wstring nostring = L"?";
        if (phrase[i][0] == '.' || phrase[i][0] == '-') {
            decorate_big_button(enterPhrase[i], L"?", 35, {0, 0, 139, 230},sf::Color::Cyan, pass + i * 80, 400,
                                70, 70);
        } else {
            enterPhrase[i]->colorChange = false;
            decorate_big_button(enterPhrase[i], phrase[i], 35, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 400,
                                70, 70);
        }
    }

}

AllLevels::AllLevels(){
    std::cout<<"7";
    Factory* factory = new LevelListFactory();
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    std::cout<<'*';
    LevelButtons = factory->create_all_tolevellist_buttons(15);
    std::cout<<'*';
    MenuButton = big_buttons[0];
    decorate_big_button(MenuButton, L"Вернуться\nк меню", 35, {0, 0, 139, 230}, sf::Color::Green, 480, 650,
                        240, 100);
    std::cout<<'*';
    for(int i =0;i<15;++i){
        decorate_to_level_button(LevelButtons[i], i);
        LevelButtons[i]->setComplexity(i/5);
        LevelButtons[i]->setNumberOfLevel(i%5);
    }
}

Alphabet::Alphabet() {
    Factory* factory = new MorzeFactory();
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    MenuButton = big_buttons[0];
    AlphabetButton =big_buttons[1];
    decorate_big_button(MenuButton, L"Вернуться\nк меню", 35, {100, 200, 40, 230},sf::Color::Blue, 480, 650,
                        240, 100);
    decorate_photo_button(AlphabetButton);
    AlphabetButton->colorChange = false;

}

GameChecked::GameChecked(std::vector<std::wstring> players_answer, std::vector<bool> players_mistakes, int cur_level, int cur_complexity){
    level = cur_level;
    complexity = cur_complexity;
    std::vector<TransportButton*> big_buttons = factory->create_all_transport_buttons();
    std::vector<LetterButton*> lettersbut =  factory->create_all_letter_buttons(18);
    ToLevelListButton = big_buttons[0];
    AgainButton = big_buttons[1];
    std::vector<Label*> labels = factory->create_all_labels();
    Label0 = labels[0];
    NextButton = big_buttons[2];
    decorate_big_button(ToLevelListButton, L"К выбору\nуровней", 35, {0, 0, 139, 230},
                        sf::Color::Yellow, 500, 550,
                        250, 150);
    decorate_big_button(AgainButton, L"Заново", 35, {0, 0, 139, 230},
                        sf::Color::Yellow, 120, 550,
                        250, 150);
    decorate_big_button(NextButton, L"Следующий\nуровень", 35, {0, 0, 139, 230},
            sf::Color::Yellow, 830, 550,
            250, 150);
    decorate_label_level(Label0, level, complexity);

    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};
    for(int i =0;i<9;++i){
        givenPhrase.push_back(lettersbut[i]);
        enterPhrase.push_back(lettersbut[i+9]);
    }

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        decorate_big_button(givenPhrase[i], phrase[i], 35, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 270,
                            70, 70);
        givenPhrase[i]->colorChange = false;
    }

    for (int i = 0; i < givenPhrase.size(); ++i) {
        enterPhrase[i]->colorChange = false;
        std::wstring nostring = L" ";
        decorate_big_button(enterPhrase[i], players_answer[i], 35, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 400,
                            70, 70);
        if(!players_mistakes[i]){
            enterPhrase[i]->setFillColor(sf::Color::Red);
        }
    }
}
