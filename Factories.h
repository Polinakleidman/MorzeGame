#pragma once
#include<vector>
#include "Buttons.h"
#include "Label.h"
#include<string>
//#include "Windows.h"

class Factory{
public:
    virtual std::vector<TransportButton*> create_all_transport_buttons() = 0;
    virtual std::vector<LetterButton*> create_all_letter_buttons(size_t number) = 0;
    virtual std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) = 0;
    virtual std::vector<Label*> create_all_labels() = 0;
};


class MenuFactory: public Factory{
public:
    MenuFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class MorzeFactory: public Factory{
public:
    MorzeFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class LevelListFactory: public Factory{
public:
    LevelListFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class GameProcessFactory: public Factory{
public:
    GameProcessFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class GameCheckedFactory: public Factory{
public:
    GameCheckedFactory() = default;
    std::vector<TransportButton*> create_all_transport_buttons() override;
    std::vector<LetterButton*> create_all_letter_buttons(size_t number) override;
    std::vector<ToLevelButton*> create_all_tolevellist_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};
