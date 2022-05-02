#pragma once
#include "LevelListFactory.h"


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