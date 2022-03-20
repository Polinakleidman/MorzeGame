#pragma once
#include <iostream>
#include "Interfaces.cpp"
#include "TransportButton.cpp"
#include "LetterButton.cpp"
#include "Label.cpp"
#include "SFML/Graphics.hpp"

void work_with_Level_List(){
    AllLevels levels;
    sf::RenderWindow& levelsWindow = levels.createAllLevelsWindow();
    std::vector< back = alphabet.CreateBackToMenuButton();
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