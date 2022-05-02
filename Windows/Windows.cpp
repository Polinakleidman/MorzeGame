#pragma once
#include "Windows.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "Windows.h"
#include "SFML/Graphics.hpp"
#include<string>
#include<vector>
#include<fstream>

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
    texture.loadFromFile("../Alphabet.png");
    AlphabetPhoto->setTexture(texture);
    AlphabetPhoto->setPosition({150, 70});
    AlphabetPhoto->setSize({900, 520});
}
