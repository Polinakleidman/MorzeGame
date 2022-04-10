#pragma once
#include <iostream>
#include "Windows.h"
#include "Label.h"
#include "SFML/Graphics.hpp"
#include<string>


void work_with_menu_window();
void work_with_level_window(int, int);
/*
int work_with_checked_level(const std::vector<bool>& checked_letters, const std::string& phrase0){
    GameChecked level;
    sf::RenderWindow& levelWindow = level.createCheckedLevelWindow();
    ToLevelListButton toLevelListButton = level.CreateToLevelListButton();
    AgainButton againButton = level.CreateAgainButton();
    NextLevelButton nextLevelButton = level.CreateNextButton();
    Label phrase = level.CreateColoredPhrase(phrase0, checked_letters);
    while (levelWindow.isOpen())
    {
        sf::Event event;

        while (levelWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                levelWindow.close();
                return 2;
            }
        }

        if (toLevelListButton.isClicked()){
            levelWindow.close();
            return 2;
        }

        if (againButton.isClicked()){
            levelWindow.close();
            return 0;
        }
        if (nextLevelButton.isClicked()){
            levelWindow.close();
            return 1;
        }
        levelWindow.display();
    }
}

bool work_with_level(int complexity, int number){
    GameProcess level;
    sf::RenderWindow& levelWindow = level.createLevelWindow();
    ToLevelListButton back = level.CreateToLevelListButton();
    CheckButton checkButton = level.CreateCheckButton();
    std::string phrase0 ="как дела";//тут надо считать с текстового файла по complexity и number
    Label phrase = level.CreatePhrase(phrase0);
    std::vector<LetterButton> clickablePhrase = level.CreatePhraseWithButtons(phrase, complexity*5+number);
    while (levelWindow.isOpen())
    {
        sf::Event event;

        while (levelWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                levelWindow.close();
                return false;
            }
        }

        if (back.isClicked()){
            levelWindow.close();
            return false;
        }

        for(int i=0;i<clickablePhrase.size();++i){
            if (clickablePhrase[i].isClicked()){
                sf::Font font;
                sf::Text letter("a", font);//вместо a будет считывание с клавиатуры
                clickablePhrase[i].writeLetter(letter);
            }
        }

        if (checkButton.isClicked()){
            std::vector<bool> answers;
            for(auto elem :clickablePhrase){
                answers.push_back(elem.is_correct());
            }
            int result = work_with_checked_level(answers, phrase0);
            if (result==0){//то есть again
                continue;
            }else if (result ==1){ // то есть next
                levelWindow.close();
                return true;
            }else if (result==2){//то есть backtolevellist
                levelWindow.close();
                return false;
            }
        }
        levelWindow.display();
    }
}
*/
void work_with_Level_List(){
    AllLevels allLevels;
    //Alphabet alphabet;
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

            if (allLevels.MenuButton.isPressed()) {
                allLevelsWindow.close();
                work_with_menu_window();
            }


            for (auto a:allLevels.LevelButtons){
                if (a.isPressed()){
                    allLevelsWindow.close();
                    work_with_level_window(a.getNumberOfLevel()+1, a.getComlexity()+1);
                    std::cout<<a.getNumberOfLevel()<<" "<<a.getComlexity();
                }
            }

            allLevelsWindow.clear(sf::Color::White);

            if(!flag){
                allLevels.MenuButton.draw(allLevelsWindow);
                for (auto& a: allLevels.LevelButtons){
                    a.draw(allLevelsWindow);
                }
            }
            allLevelsWindow.display();
        }
    }
}

/*
void work_with_Morze_window(){
    Alphabet alphabet;
    sf::RenderWindow& alphabetWindow = alphabet.createAlphabetWindow();
    BackToMenuButton back = alphabet.CreateBackToMenuButton();
    while (alphabetWindow.isOpen())
    {
        sf::Event event;

        while (alphabetWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                alphabetWindow.close();
        }

        if (back.isClicked()){
            alphabetWindow.close();
        }
        alphabetWindow.display();
        //alphabetWindow.draw(picture); это должно быть изи
    }

}
*/

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

            if (alphabet.MenuButton.isPressed()) {
                AlphabetWindow.close();
                work_with_menu_window();
            }

            AlphabetWindow.clear(sf::Color::White);

            if(!flag){
                alphabet.MenuButton.draw(AlphabetWindow);
                alphabet.AlphabetButton.draw(AlphabetWindow);
            }
            AlphabetWindow.display();
        }
    }
}

void work_with_menu_window(){
    setlocale(LC_ALL, "russian");
    Menu menu;
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

            if (menu.WatchMorzeButton.isPressed()) {
                MenuWindow.close();
                work_with_Morze_window();
            } else if (menu.ToLevelListButton.isPressed()) {
                MenuWindow.close();
                work_with_Level_List();
            }
        }

        MenuWindow.clear(sf::Color::White);

        if(!flag){
            menu.WatchMorzeButton.draw(MenuWindow);
            menu.ToLevelListButton.draw(MenuWindow);
            menu.Label0.draw(MenuWindow);
            menu.LabelMorze.draw(MenuWindow);
        }
        MenuWindow.display();
    }
}


void work_with_level_window(int level, int complexity){
    setlocale(LC_ALL, "russian");
    GameProcess gameprocess(level, complexity);
    sf::RenderWindow GPWindow;
    gameprocess.render(GPWindow);
    std::cout<<"ok1";
    std::cout<<"ok2";
    std::cout<<"ok";
    std::wstring Text = L"a";
    bool flag = false;

    while (GPWindow.isOpen())
    {
        sf::Event event;

        while (GPWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                GPWindow.close();
            }

            if (gameprocess.ToLevelListButton.isPressed()) {
                GPWindow.close();
                work_with_Level_List();
            } else if (gameprocess.CheckButton.isPressed()) {
                GPWindow.close();
                for(auto x: gameprocess.enterPhrase){
                    std::cout<<x.is_correct()<<"*";
                }
                //work_with_Level_List();
            }else{
                for(auto& but: gameprocess.enterPhrase){
                    if (but.isPressed() && but.colorChange){
                        //GPWindow.close();
//                        but.writeLetter();
                    but.set_all(Text, 35, {0, 0, 139, 230},
            "../button.png", middle, middle, sf::Color::Yellow, 120, 100,
            80, 80);
                    }
                }
            }
        }

        GPWindow.clear(sf::Color::White);

        if(!flag){
            gameprocess.CheckButton.draw(GPWindow);
            gameprocess.ToLevelListButton.draw(GPWindow);
            gameprocess.Label0.draw(GPWindow);
            for(auto& but: gameprocess.givenPhrase){
                but.draw(GPWindow);
            }
            for(auto& but: gameprocess.enterPhrase){
                but.draw(GPWindow);
            }
        }
        GPWindow.display();
    }

}


int main(){
    work_with_menu_window();
}
