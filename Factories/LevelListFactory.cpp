#pragma once
#include "LevelListFactory.h"


std::vector<Button*> LevelListFactory::create_all_transport_buttons() {
    Button* BackToMenu = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(BackToMenu);
    return all_buttons;
}

std::vector<Button *> LevelListFactory::create_all_letter_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Button*> LevelListFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    for(size_t i = 0; i < number; ++i){
        all_buttons.push_back(new ToLevelButton());
    }
    return all_buttons;
}

std::vector<Label*> LevelListFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}