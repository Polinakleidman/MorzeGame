#pragma once
#include "Factories.h"

class LevelListFactory: public Factory{
public:
    LevelListFactory() = default;
    std::vector<Button*> create_all_transport_buttons() override;
    std::vector<Button*> create_all_letter_buttons(size_t number) override;
    std::vector<Button*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};