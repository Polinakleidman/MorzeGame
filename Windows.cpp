#pragma once
#include "Windows.h"
#include "SFML/graphics.hpp"
#include <iostream>
#include <vector>
#include "Windows.h"
#include "SFML/graphics.hpp"
#include<string>
#include<vector>

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
//    auto tuple_of_everything = factory->create_everything();
//    Button* WatchMorzeButton = tuple_of_everything[0];
////    std::cout<<"*";
////    factory->CreateMorzeButton(WatchMorzeButton);
////    std::cout<<"*";
//    Button* ToLevelListButton = tuple_of_everything[1];
////    factory->CreateToLevelListButton(ToLevelListButton);
//    Label* Label0 = tuple_of_everything[2];
//    Label* LabelMorze = tuple_of_everything[3];
//    factory->CreateLabel(Label0);
//    factory->CreateLabelMorze(LabelMorze);

}

GameProcess::GameProcess(int cur_level, int cur_complexity) {

    level = cur_level;
    complexity = cur_complexity;
    Button* ToLevelListButton = new Button;
    factory->CreateToLevelListButton(ToLevelListButton);
    Button* CheckButton = new Button;
    factory->CreateCheckButton(CheckButton);
    Label* Label0 = new Label;
    factory->CreateLabel(Label0, level, complexity);

    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};

    givenPhrase = std::vector<LetterButton*>(phrase.size());
    enterPhrase = std::vector<LetterButton*>(phrase.size());

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        givenPhrase[i]->colorChange = false;
        givenPhrase[i]->setApproriateLetter(phrase[i]);
        factory->CreateLetterButton(givenPhrase[i], pass + i * 80, 270, phrase[i]);
        enterPhrase[i]->setApproriateLetter(phrase[i]);
    }


    for (int i = 0; i < givenPhrase.size(); ++i) {
        std::wstring nostring = L"?";
        if (phrase[i][0] == '.' || phrase[i][0] == '-') {
            factory->CreateLetterButton(enterPhrase[i], pass + i * 80, 400, L"?");
            enterPhrase[i]->setFillColor(sf::Color::Cyan);
        } else {
            enterPhrase[i]->colorChange = false;
            factory->CreateLetterButton(enterPhrase[i], pass + i * 80, 400, phrase[i]);
        }
    }
}

AllLevels::AllLevels(){
    Button* MenuButton = new Button;
    LevelButtons = std::vector<ToLevelButton*>(15);
    factory->CreateMenuButton(MenuButton);
    for(int i =0;i<15;++i){
        factory->CreateToLevelButtons(LevelButtons[i], i);
        LevelButtons[i]->setComplexity(i/5);
        LevelButtons[i]->setNumberOfLevel(i%5);
    }
}

Alphabet::Alphabet() {
    Button* MenuButton = new Button;
    Button* AlphabetButton = new Button;
    AlphabetButton->colorChange = false;
    factory->CreateMorzeAlphabet(AlphabetButton);
    factory->CreateMenuButton(MenuButton);

}

GameChecked::GameChecked(std::vector<std::wstring> players_answer, std::vector<bool> players_mistakes, int cur_level, int cur_complexity){
    level = cur_level;
    complexity = cur_complexity;
    Button* ToLevelListButton = new Button;
    factory->CreateToLevelListButton(ToLevelListButton);
    Button* AgainButton = new Button;
    factory->CreateAgainButton(AgainButton);
    Label* Label0 = new Label;
    factory->CreateLabel(Label0, level, complexity);
    Button* NextButton = new Button;
    factory->CreateNextLevelButton(NextButton);


    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};

    givenPhrase = std::vector<LetterButton*>(phrase.size());
    enterPhrase = std::vector<LetterButton*>(phrase.size());

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        factory->CreateLetterButton(givenPhrase[i], pass + i * 80, 270, phrase[i]);
        givenPhrase[i]->colorChange = false;
    }

    for (int i = 0; i < givenPhrase.size(); ++i) {
        enterPhrase[i]->colorChange = false;
        std::wstring nostring = L" ";
        factory->CreateLetterButton(enterPhrase[i], pass + i * 80, 400, players_answer[i]);
        if(!players_mistakes[i]){
            enterPhrase[i]->setFillColor(sf::Color::Red);
        }
    }
}
