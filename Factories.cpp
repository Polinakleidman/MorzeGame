#pragma once
#include"Factories.h"
#include <iostream>

//---------------------------------------------------------------------------//

std::vector<TransportButton*> MenuFactory::create_all_transport_buttons() {
    TransportButton* WatchMorzeButton = new TransportButton();
    TransportButton* ToLevelListButton = new TransportButton();
    std::vector<TransportButton*> all_buttons;
    all_buttons.push_back(WatchMorzeButton);
    all_buttons.push_back(ToLevelListButton);
    return all_buttons;
}
std::vector<LetterButton*> MenuFactory::create_all_letter_buttons(size_t number) {
    std::vector<LetterButton*> all_buttons;
    return all_buttons;
}

std::vector<ToLevelButton *> MenuFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<ToLevelButton*> all_buttons;
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

std::vector<TransportButton*> LevelListFactory::create_all_transport_buttons() {
    TransportButton* BackToMenu = new TransportButton();
    std::vector<TransportButton*> all_buttons;
    all_buttons.push_back(BackToMenu);
    return all_buttons;
}

std::vector<LetterButton *> LevelListFactory::create_all_letter_buttons(size_t number) {
    std::vector<LetterButton*> all_buttons;
    return all_buttons;
}

std::vector<ToLevelButton*> LevelListFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<ToLevelButton*> all_buttons;
    for(size_t i = 0; i < number; ++i){
        all_buttons.push_back(new ToLevelButton());
    }
    return all_buttons;
}

std::vector<Label*> LevelListFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}

//--------------------------------------------------------------------------//

std::vector<TransportButton*> GameProcessFactory::create_all_transport_buttons() {
    TransportButton* ToLevelList = new TransportButton();
    TransportButton* CheckButton = new TransportButton();
    std::vector<TransportButton*> all_buttons;
    all_buttons.push_back(ToLevelList);
    all_buttons.push_back(CheckButton);
    return all_buttons;
}

std::vector<LetterButton*> GameProcessFactory::create_all_letter_buttons(size_t number) {
    std::vector<LetterButton*> all_buttons;
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

std::vector<ToLevelButton *> GameProcessFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<ToLevelButton*> all_buttons;
    return all_buttons;
}

//----------------------------------------------------------------------------//

std::vector<TransportButton*> MorzeFactory::create_all_transport_buttons() {
    TransportButton* BackToMenu = new TransportButton();
    TransportButton* ALphabetButton = new TransportButton();
    std::vector<TransportButton*> all_buttons;
    all_buttons.push_back(BackToMenu);
    all_buttons.push_back(ALphabetButton);
    return all_buttons;
}

std::vector<LetterButton *> MorzeFactory::create_all_letter_buttons(size_t number) {
    std::vector<LetterButton*> all_buttons;
    return all_buttons;
}

std::vector<ToLevelButton *> MorzeFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<ToLevelButton*> all_buttons;
    return all_buttons;
}

std::vector<Label*> MorzeFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}

//-------------------------------------------------------------------------//

std::vector<TransportButton*> GameCheckedFactory::create_all_transport_buttons() {
    TransportButton* Again = new TransportButton();
    TransportButton* Next = new TransportButton();
    TransportButton* ToList = new TransportButton();
    std::vector<TransportButton*> all_buttons;
    all_buttons.push_back(Again);
    all_buttons.push_back(Next);
    all_buttons.push_back(ToList);
    return all_buttons;
}

std::vector<LetterButton *> GameCheckedFactory::create_all_letter_buttons(size_t number) {
    std::vector<LetterButton*> all_buttons;
    for(int i = 0; i < number; ++i){
        all_buttons.push_back(new LetterButton());
    }
    return all_buttons;
}

std::vector<ToLevelButton *> GameCheckedFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<ToLevelButton*> all_buttons;
    return all_buttons;
}

std::vector<Label *> GameCheckedFactory::create_all_labels() {
    Label* LevelText = new Label();
    std::vector<Label*> all_labels;
    all_labels.push_back(LevelText);
    return all_labels;
}

//--------------------------------------------------------------------------//