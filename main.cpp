#pragma once
#include <iostream>
#include "Windows/Windows.h"
#include "Label.h"
#include "SFML/Graphics.hpp"
#include "Windows/MenuWindow.h"
#include "Windows/AlphabetWindow.h"
#include "Windows/AllLevelsWindow.h"
#include "Windows/GameWindows.h"
#include<string>



void work_with_menu_window();
void work_with_level_window(int, int);
void work_with_checked_level(std::vector<std::wstring> playersAnswer, std::vector<bool> playerMistakes, int level, int complexity);
void work_with_Level_List();

void work_with_Level_List(){
    std::cout<<2;
    AllLevels allLevels;
    std::cout<<2;
    sf::RenderWindow allLevelsWindow;
    allLevels.render(allLevelsWindow);
    bool flag = false;
    while (allLevelsWindow.isOpen())
    {
        sf::Event event;

        while (allLevelsWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                allLevelsWindow.close();
            }

            if (allLevels.MenuButton->isPressed()) {
                allLevelsWindow.close();
                work_with_menu_window();
            }


            for (auto& a:allLevels.LevelButtons){
                if (a->isPressed()){
                    allLevelsWindow.close();
                    work_with_level_window(a->getNumberOfLevel()+1, a->getComlexity()+1);
                    std::cout<<a->getNumberOfLevel()<<" "<<a->getComlexity();
                }
            }

            allLevelsWindow.clear(sf::Color::White);

            if(!flag){
                allLevels.MenuButton->draw(allLevelsWindow);
                for (auto& a: allLevels.LevelButtons){
                    a->draw(allLevelsWindow);
                }
            }
            allLevelsWindow.display();
        }
    }
}


void work_with_Morze_window(){
    setlocale(LC_ALL, "russian");
    Alphabet alphabet;
    sf::RenderWindow AlphabetWindow;
    alphabet.render(AlphabetWindow);
    bool flag = false;

    while (AlphabetWindow.isOpen())
    {
        sf::Event event;

        while (AlphabetWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                AlphabetWindow.close();
            }

            if (alphabet.MenuButton->isPressed()) {
                AlphabetWindow.close();
                work_with_menu_window();
            }

            AlphabetWindow.clear(sf::Color::White);

            if(!flag){
                alphabet.MenuButton->draw(AlphabetWindow);
                alphabet.AlphabetButton->draw(AlphabetWindow);
            }
            AlphabetWindow.display();
        }
    }
}

void work_with_menu_window(){
    setlocale(LC_ALL, "russian");
    Menu menu;
    std::cout<<1;
    sf::RenderWindow MenuWindow;
    menu.render(MenuWindow);
    std::cout<<"ok1";
    std::cout<<"ok2";
    std::cout<<"ok";

    bool flag = false;

    while (MenuWindow.isOpen())
    {
        sf::Event event;

        while (MenuWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                MenuWindow.close();
            }

            if (menu.WatchMorzeButton->isPressed()) {
                MenuWindow.close();
                work_with_Morze_window();
            } else if (menu.ToLevelListButton->isPressed()) {
                MenuWindow.close();
                work_with_Level_List();
            }
        }

        MenuWindow.clear(sf::Color::White);

        if(!flag){
            menu.WatchMorzeButton->draw(MenuWindow);
            menu.ToLevelListButton->draw(MenuWindow);
            menu.Label0->draw(MenuWindow);
            menu.LabelMorze->draw(MenuWindow);
        }
        MenuWindow.display();
    }
}


void work_with_level_window(int level, int complexity){
//    setlocale(LC_ALL, "russian");
    GameProcess gameprocess(level, complexity);
    std::cout<<"*";
    sf::RenderWindow GPWindow;
    gameprocess.render(GPWindow);
    bool flag = false;
    std::vector<bool> ifCorrectAnswer;
    int curr = -1;
    std::wstring line;
    std::vector<std::wstring> PlayerAnswer(100);// = {{L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "}};
    while (GPWindow.isOpen())
    {
        sf::Event event;

        while (GPWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                GPWindow.close();
            }
            if (event.type==sf::Event::TextEntered && curr!=-1){
                switch (event.text.unicode) {
                    case 0xD:
                        gameprocess.enterPhrase[curr]->writeLetter(line);
                        line = L"";
                        curr = -1;
                        break;
                    default:
                    {
                        line += static_cast<wchar_t> (event.text.unicode);
                        gameprocess.enterPhrase[curr]->writeLetter(line);
                        std::wcout<<line<<curr;
                        line = L"";
                        curr = -1;
                        break;
                    }
                }
            }
            if (gameprocess.ToLevelListButton->isPressed()) {
                GPWindow.close();
                work_with_Level_List();
            } else if (gameprocess.CheckButton->isPressed()) {
                for(int i =0;i<gameprocess.enterPhrase.size();++i){
                    auto x = gameprocess.enterPhrase[i];
                    ifCorrectAnswer.push_back(x->is_correct());
                    PlayerAnswer[i] = x->getLetter();
                }
                GPWindow.close();
                work_with_checked_level(PlayerAnswer, ifCorrectAnswer, level, complexity);
            }else{
                for(int i =0;i<gameprocess.enterPhrase.size();++i){

                    if (gameprocess.enterPhrase[i]->isPressed() && gameprocess.enterPhrase[i]->colorChange){

                        curr = i;
                    }
                }

            }
        }

        GPWindow.clear(sf::Color::White);

        if(!flag){
            gameprocess.CheckButton->draw(GPWindow);
            gameprocess.ToLevelListButton->draw(GPWindow);
            gameprocess.Label0->draw(GPWindow);
            for(auto& but: gameprocess.givenPhrase){
                but->draw(GPWindow);
            }
            for(auto& but: gameprocess.enterPhrase){
                but->draw(GPWindow);
            }
        }
        GPWindow.display();
    }

}

void work_with_checked_level(std::vector<std::wstring> playersAnswer, std::vector<bool> playerMistakes, int level, int complexity){
    //setlocale(LC_ALL, "russian");
    std::cout<<'*';
    GameChecked gamechecked(playersAnswer,playerMistakes, level, complexity);
    std::cout<<2;
    sf::RenderWindow GPWindow;
    gamechecked.render(GPWindow);

    bool flag = false;

    while (GPWindow.isOpen())
    {
        sf::Event event;

        while (GPWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                GPWindow.close();
            }

            if (gamechecked.ToLevelListButton->isPressed()) {
                GPWindow.close();
                work_with_Level_List();
            } else if (gamechecked.NextButton->isPressed()) {
                GPWindow.close();
                if(level < 5){
                    work_with_level_window(level + 1, complexity);
                } else if (complexity < 3){
                    work_with_level_window(1, complexity + 1);
                } else {
                    work_with_Level_List();
                }
            } else if(gamechecked.AgainButton->isPressed()){
                GPWindow.close();
                work_with_level_window(level, complexity);
            }
        }

        GPWindow.clear(sf::Color::White);

        if(!flag){
            gamechecked.AgainButton->draw(GPWindow);
            gamechecked.ToLevelListButton->draw(GPWindow);
            gamechecked.NextButton->draw(GPWindow);
            gamechecked.Label0->draw(GPWindow);
            for(auto but: gamechecked.givenPhrase){
                but->draw(GPWindow);
            }
            for(auto but: gamechecked.enterPhrase){
                but->draw(GPWindow);
            }
        }
        GPWindow.display();
    }
}

int main() {
    work_with_menu_window();
}
