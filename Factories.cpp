#pragma once
#include"Factories.h"
#include <iostream>

//---------------------------------------------------------------------------//

std::vector<Button*> MenuFactory::create_all_big_buttons() {
    Button* WatchMorzeButton = new TransportButton();
    Button* ToLevelListButton = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(WatchMorzeButton);
    all_buttons.push_back(ToLevelListButton);
    return all_buttons;
}
std::vector<Button*> MenuFactory::create_all_small_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Label*> MenuFactory::create_all_labels() {
    Label* LabelTitle = new Label();
    Label* MorzeLabel = new Label();
    std::vector<Label*> answer;
    answer.push_back(LabelTitle);
    answer.push_back(MorzeLabel);
    return answer;
}

//-------------------------------------------------------------------------//

std::vector<Button*> LevelListFactory::create_all_big_buttons() {
    Button* BackToMenu = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(BackToMenu);
    return all_buttons;
}

std::vector<Button *> LevelListFactory::create_all_small_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    for(size_t i = 0; i < number; ++i){
        all_buttons.push_back(new ToLevelButton());
    }
    return all_buttons;
}

std::vector<Label *> LevelListFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}

//--------------------------------------------------------------------------//

std::vector<Button*> GameProcessFactory::create_all_big_buttons() {
    Button* ToLevelList = new TransportButton();
    Button* CheckButton = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(ToLevelList);
    all_buttons.push_back(CheckButton);
    return all_buttons;
}

std::vector<Button*> GameProcessFactory::create_all_small_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    for(size_t i = 0; i < number; ++i){
        all_buttons.push_back(new LetterButton());
    }
    return all_buttons;
}

std::vector<Label*> GameProcessFactory::create_all_labels() {
    Label* LevelText = new Label();
    std::vector<Label*> all_labels;
    all_labels.push_back(LevelText);
    return all_labels;
}

//----------------------------------------------------------------------------//

std::vector<Button *> MorzeFactory::create_all_big_buttons() {
    Button* BackToMenu = new TransportButton();
    Button* ALphabetButton = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(BackToMenu);
    all_buttons.push_back(ALphabetButton);
    return all_buttons;
}

std::vector<Button *> MorzeFactory::create_all_small_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Label*> MorzeFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}

//-------------------------------------------------------------------------//

std::vector<Button *> GameCheckedFactory::create_all_big_buttons() {
    Button* Again = new TransportButton();
    Button* Next = new TransportButton();
    Button* ToList = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(Again);
    all_buttons.push_back(Next);
    all_buttons.push_back(ToList);
    return all_buttons;
}

std::vector<Button *> GameCheckedFactory::create_all_small_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    for(int i = 0; i < number; ++i){
        all_buttons.push_back(new LetterButton());
    }
    return all_buttons;
}

std::vector<Label *> GameCheckedFactory::create_all_labels() {
    Label* LevelText = new Label();
    std::vector<Label*> all_labels;
    all_labels.push_back(LevelText);
    return all_labels;
}

//--------------------------------------------------------------------------//