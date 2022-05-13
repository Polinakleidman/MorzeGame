#pragma once
#include "Factories.h"

class MorzeFactory: public Factory{
public:
    MorzeFactory() = default;
    std::vector<Button*> create_all_transport_buttons() override;
    std::vector<Button*> create_all_letter_buttons(size_t number) override;
    std::vector<Button*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};