#pragma once
#include "Factories.h"

class MenuFactory: public Factory{
public:
    MenuFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};