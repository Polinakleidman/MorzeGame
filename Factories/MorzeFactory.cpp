#pragma once
#include "MorzeFactory.h"

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
