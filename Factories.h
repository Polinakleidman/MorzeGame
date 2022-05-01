#pragma once
#include<vector>
#include "Buttons.h"
#include "Label.h"
#include<string>
#include "Windows.h"

class Factory{
public:
    virtual std::vector<Button*> create_all_big_buttons() = 0;
    virtual std::vector<Button*> create_all_small_buttons(size_t number) = 0;
    virtual std::vector<Label*> create_all_labels() = 0;
};


class MenuFactory: public Factory{
public:
    MenuFactory() = default;
    std::vector<Button*> create_all_big_buttons() override;
    std::vector<Button*> create_all_small_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class MorzeFactory: public Factory{
public:
    MorzeFactory() = default;
    std::vector<Button*> create_all_big_buttons() override;
    std::vector<Button*> create_all_small_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class LevelListFactory: public Factory{
public:
    LevelListFactory() = default;
    std::vector<Button*> create_all_big_buttons() override;
    std::vector<Button*> create_all_small_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class GameProcessFactory: public Factory{
public:
    GameProcessFactory() = default;
    std::vector<Button*> create_all_big_buttons() override;
    std::vector<Button*> create_all_small_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;
};

class GameCheckedFactory: public Factory{
public:
    GameCheckedFactory() = default;
    std::vector<Button*> create_all_big_buttons() override;
    std::vector<Button*> create_all_small_buttons(size_t number) override;
    std::vector<Label*> create_all_labels() override;

};
