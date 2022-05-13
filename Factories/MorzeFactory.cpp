#pragma once
#include "MorzeFactory.h"

std::vector<Button*> MorzeFactory::create_all_transport_buttons() {
    Button* BackToMenu = new TransportButton();
    Button* ALphabetButton = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(BackToMenu);
    all_buttons.push_back(ALphabetButton);
    return all_buttons;
}

std::vector<Button *> MorzeFactory::create_all_letter_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Button *> MorzeFactory::create_all_tolevellist_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Label*> MorzeFactory::create_all_labels() {
    std::vector<Label*> all_labels;
    return all_labels;
}
