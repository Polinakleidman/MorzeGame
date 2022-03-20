#pragma once
#include <iostream>
#include "Interfaces.cpp"
#include "TransportButton.cpp"
#include "LetterButton.cpp"
#include "Label.cpp"
#include "SFML/Graphics.hpp"

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

void work_with_Level_List(){
    AllLevels levels;
    sf::RenderWindow& levelsWindow = levels.createAllLevelsWindow();
    BackToMenuButton back = levels.CreateBackToMenuButton();
    std::vector<ToLevelButton> levelbuttons =levels.CreatelevelsButtons();
    while (levelsWindow.isOpen())
    {
        sf::Event event;

        while (levelsWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                levelsWindow.close();
        }

        if (back.isClicked()){
            levelsWindow.close();
        }

        for (int i=0;i<levelbuttons.size();++i){
            if (levelbuttons[i].isClicked()){
                bool nextLevel = work_with_level(levelbuttons[i].getComlexity(), levelbuttons[i].getNumberOfLevel());
                int pos = i;
                while (nextLevel && pos<levelbuttons.size() - 1){
                    ++pos;
                    nextLevel = work_with_level(levelbuttons[pos].getNumberOfLevel(), levelbuttons[pos].getNumberOfLevel());
                }
            }
        }

        levelsWindow.display();
        //alphabetWindow.draw(picture); это должно быть изи
    }
}


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

void work_with_menu_window(){
    Menu menu;
    Alphabet alphabet;
    sf::RenderWindow& menuWindow = menu.createMenuWindow();
    WatchMorzeButton but1 = menu.CreateMorzeButton();
    ToLevelListButton but2 = menu.CreateToLevelListButton();
    while (menuWindow.isOpen())
    {
        sf::Event event;

        while (menuWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menuWindow.close();
        }

        if (but1.isClicked()){
            menuWindow.close();
            work_with_Morze_window();
        }else if (but2.isClicked()){
            menuWindow.close();
            work_with_Level_List();
        }
        menuWindow.display();
    }
}



int main(){
    work_with_menu_window();
}