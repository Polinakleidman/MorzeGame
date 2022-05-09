#pragma once
#include "GameCheckedFactory.h"

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
