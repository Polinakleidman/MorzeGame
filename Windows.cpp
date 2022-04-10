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

    WatchMorzeButton = Button();
    factory.CreateMorzeButton(WatchMorzeButton);
    ToLevelListButton = Button();
    factory.CreateToLevelListButton(ToLevelListButton);
    Label0 = Label();
    LabelMorze = Label();
    factory.CreateLabel(Label0);
    factory.CreateLabelMorze(LabelMorze);

}

GameProcess::GameProcess(int cur_level, int cur_complexity) {

    level = cur_level;
    complexity = cur_complexity;
    ToLevelListButton = Button();
    factory.CreateToLevelListButton(ToLevelListButton);
    CheckButton = Button();
    factory.CreateCheckButton(CheckButton);
    Label0 = Label();
    factory.CreateLabel(Label0, level, complexity);

    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};

    givenPhrase = std::vector<LetterButton>(phrase.size());
    enterPhrase = std::vector<LetterButton>(phrase.size());

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        givenPhrase[i].colorChange = false;
        givenPhrase[i].setApproriateLetter(phrase[i]);
        factory.CreateLetterButton(givenPhrase[i], pass + i * 80, 270, phrase[i]);
        enterPhrase[i].setApproriateLetter(phrase[i]);
    }


    for (int i = 0; i < givenPhrase.size(); ++i) {
        std::wstring nostring = L" ";
        if (phrase[i][0] == '.' || phrase[i][0] == '-') {
            factory.CreateLetterButton(enterPhrase[i], pass + i * 80, 400, L"?");
            enterPhrase[i].setFillColor(sf::Color::Cyan);
        } else {
            enterPhrase[i].colorChange = false;
            factory.CreateLetterButton(enterPhrase[i], pass + i * 80, 400, phrase[i]);
        }
    }
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

Alphabet::Alphabet() {
    MenuButton = Button();
    AlphabetButton = Button();
    AlphabetButton.colorChange = false;
    factory.CreateMorzeAlphabet(AlphabetButton);
    factory.CreateMenuButton(MenuButton);

}

GameChecked::GameChecked(std::vector<bool> players_answer, int cur_level, int cur_complexity){
    level = cur_level;
    complexity = cur_complexity;
    ToLevelListButton = Button();
    factory.CreateToLevelListButton(ToLevelListButton);
    AgainButton = Button();
    factory.CreateAgainButton(AgainButton);
    Label0 = Label();
    factory.CreateLabel(Label0, level, complexity);
    NextButton = Button();
    factory.CreateNextLevelButton(NextButton);


    std::vector<std::wstring> phrase = {{L"к", L"а", L"к", L" ", L"д", L".", L"л", L"a", L"?"}};

    givenPhrase = std::vector<LetterButton>(phrase.size());
    enterPhrase = std::vector<LetterButton>(phrase.size());

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        factory.CreateLetterButton(givenPhrase[i], pass + i * 80, 270, phrase[i]);
    }

    for (int i = 0; i < givenPhrase.size(); ++i) {
        std::wstring nostring = L"?";
        if (phrase[i][0] == '.' || phrase[i][0] == '-') {
            factory.CreateLetterButton(enterPhrase[i], pass + i * 80, 400, nostring);
        } else {
            enterPhrase[i].colorChange = false;
            factory.CreateLetterButton(enterPhrase[i], pass + i * 80, 400, phrase[i]);
        }
        if(!players_answer[i]){
            enterPhrase[i].setFillColor(sf::Color::Red);
        }
    }
}
