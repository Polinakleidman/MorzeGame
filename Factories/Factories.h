#pragma once
#include<vector>
#include "../Buttons.h"
#include "../Label.h"
#include<string>

class Factory{
public:
    virtual std::vector<Button*> create_all_transport_buttons() = 0;
    virtual std::vector<Button*> create_all_letter_buttons(size_t number) = 0;
    virtual std::vector<Button*> create_all_tolevellist_buttons(size_t number) = 0;
    virtual std::vector<Label*> create_all_labels() = 0;
};
