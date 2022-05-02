#pragma once
#include "GameProcessFactory.h"

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
