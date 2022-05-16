#pragma once
#include "GameWindows.h"
#include "../Levels/Complexity1.cpp"
#include "../Levels/Complexity2.cpp"
#include "../Levels/Complexity3.cpp"

void GameProcess::render(sf::Window &Window) {
    Window.create(sf::VideoMode(1200, 800), "Game is on");
}

GameProcess::GameProcess(int cur_level, int cur_complexity) {
    factory = new GameProcessFactory();
    level = cur_level;
    complexity = cur_complexity;
    std::vector<std::wstring> phrase;
    std::vector<std::wstring> real_phrase;
    if(complexity == 1){
        phrase = phrases1[(level - 1)*2+1];
        real_phrase = phrases1[(level - 1)*2];
    } else if (complexity == 2) {
        phrase = phrases2[(level - 1) * 2 + 1];
        real_phrase = phrases2[(level - 1) * 2];
    } else if (complexity == 3) {
        phrase = phrases3[(level - 1) * 2 + 1];
        real_phrase = phrases3[(level - 1) * 2];
    }
    std::cout<<"#";
    std::vector<Button*> big_buttons = factory->create_all_transport_buttons();
    std::vector<Button*> lettersbut =  factory->create_all_letter_buttons(real_phrase.size()*2);
    for(int i =0;i<real_phrase.size();++i){
        enterPhrase.push_back(lettersbut[i]);
        givenPhrase.push_back(lettersbut[i+ real_phrase.size()]);
    }
    std::vector<Label*> all_labels = factory->create_all_labels();
    ToLevelListButton = big_buttons[0];
    CheckButton = big_buttons[1];
    Label0 = all_labels[0];
    std::cout<<"9";
    decorate_big_button(ToLevelListButton, L"Вернуться\nк выбору\nуровней", 30, {0, 0, 139, 230},
                        sf::Color::Yellow, 120, 550,
                        250, 150);
    decorate_big_button(CheckButton, L"Проверить", 30, {0, 0, 139, 230},
                        sf::Color::Yellow, 830, 550,
                        250, 150);
    decorate_label_level(Label0, level, complexity);
    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;

    for (int i = 0; i < givenPhrase.size(); ++i) {
        givenPhrase[i]->colorChange = false;
        givenPhrase[i]->setApproriateLetter(real_phrase[i]);
        decorate_big_button(givenPhrase[i], phrase[i], 30, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 270,
                            70, 70);

        givenPhrase[i]->setApproriateLetter(real_phrase[i]);
    }
    for (int i = 0; i < givenPhrase.size(); ++i) {
        std::wstring nostring = L"?";
        if (phrase[i][0] == '.' || phrase[i][0] == '-') {
            decorate_big_button(enterPhrase[i], L"?", 30, {0, 0, 139, 230},sf::Color::Cyan, pass + i * 80, 400,
                                70, 70);
        } else {
            enterPhrase[i]->colorChange = false;
            decorate_big_button(enterPhrase[i], phrase[i], 30, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 400,
                                70, 70);
            enterPhrase[i]->set_letter(real_phrase[i]);
        }
        enterPhrase[i]->setApproriateLetter(real_phrase[i]);
    }
}

void GameChecked::render(sf::Window &Window) {
    Window.create(sf::VideoMode(1200, 800), "Your answer has been checked");
}

GameChecked::GameChecked(std::vector<std::wstring> players_answer, std::vector<bool> players_mistakes, int cur_level, int cur_complexity){
    factory =new GameCheckedFactory();
    level = cur_level;
    complexity = cur_complexity;
    std::vector<std::wstring> phrase;
    std::vector<std::wstring> real_phrase;
    if(complexity == 1){
        phrase = phrases1[(level - 1)*2+1];
        real_phrase = phrases1[(level - 1)*2];
    } else if (complexity == 2) {
        phrase = phrases2[(level - 1) * 2 + 1];
        real_phrase = phrases2[(level - 1) * 2];
    } else if (complexity == 3) {
        phrase = phrases3[(level - 1) * 2 + 1];
        real_phrase = phrases3[(level - 1) * 2];
    }
    std::vector<Button*> big_buttons = factory->create_all_transport_buttons();
    std::vector<Button*> lettersbut =  factory->create_all_letter_buttons(real_phrase.size()*2);
    ToLevelListButton = big_buttons[0];
    AgainButton = big_buttons[1];
    std::vector<Label*> labels = factory->create_all_labels();
    Label0 = labels[0];
    NextButton = big_buttons[2];
    std::cout<<3;
    decorate_big_button(ToLevelListButton, L"К выбору\nуровней", 30, {0, 0, 139, 230},
                        sf::Color::Yellow, 500, 550,
                        250, 150);
    decorate_big_button(AgainButton, L"Заново", 30, {0, 0, 139, 230},
                        sf::Color::Yellow, 120, 550,
                        250, 150);
    decorate_big_button(NextButton, L"Следующий\nуровень", 30, {0, 0, 139, 230},
                        sf::Color::Yellow, 830, 550,
                        250, 150);
    decorate_label_level(Label0, level, complexity);
    for(int i =0;i<real_phrase.size();++i){
        givenPhrase.push_back(lettersbut[i]);
        enterPhrase.push_back(lettersbut[i+real_phrase.size()]);
    }

    int length = givenPhrase.size() * 70 + (givenPhrase.size() - 1) * 10;
    int pass = 600 - length/2;
    for (int i = 0; i < givenPhrase.size(); ++i) {
        decorate_big_button(givenPhrase[i], phrase[i], 30, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 270,
                            70, 70);
        givenPhrase[i]->colorChange = false;
    }

    for (int i = 0; i < givenPhrase.size(); ++i) {
        enterPhrase[i]->colorChange = false;
        std::wstring nostring = L" ";
        decorate_big_button(enterPhrase[i], players_answer[i], 30, {0, 0, 139, 230},sf::Color::Yellow, pass + i * 80, 400,
                            70, 70);
        if(!players_mistakes[i]){
            enterPhrase[i]->setFillColor(sf::Color::Red);
        }
    }
}
