#pragma once
#include "MenuFactory.h"

std::vector<Button*> MenuFactory::create_all_transport_buttons() {
    Button* WatchMorzeButton = new TransportButton();
    Button* ToLevelListButton = new TransportButton();
    std::vector<Button*> all_buttons;
    all_buttons.push_back(WatchMorzeButton);
    all_buttons.push_back(ToLevelListButton);
    return all_buttons;
}
std::vector<Button*> MenuFactory::create_all_letter_buttons(size_t number) {
    std::vector<Button*> all_buttons;
    return all_buttons;
}

std::vector<Button *> MenuFactory::create_all_tolevellist_buttons(size_t number) {
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