#pragma once
#include "Buttons.h"
#include "Label.h"
class Factory{
    //таких кнопок на странице не больше одной, так что координаты не нужны
    //все будет сразу прописано в дочерней фабрике
public:
    Button CreateMenuButton();
    Button CreateMorzeButton();
    Button CreateToLevelListButton();
    Button CreateCheckButton();
    Button CreateNextLevelButton();
    Button CreateAgainButton();

    //этих кнопок на странице много - нужны координаты
    Button CreateToLevelButton(int x, int y);
    Button CreateLetterButton(int x, int y);
};

class MenuFactory: public Factory{
public:
    void CreateMorzeButton(Button&);
    void CreateToLevelListButton(Button&);
    void CreateLabel(Label&);
};

class MorzeFactory: public Factory{
    Button CreateMenuButton();
};

class LevelListFactory: public Factory{
    Button CreateMenuButton();
    Button CreateToLevelButton(int x, int y);
};

class GameProcessFactory: public Factory{
    Button CreateToLevelListButton();
    Button CreateCheckButton();
    Button CreateLetterButton(int x, int y);
};

class GameCheckedFactory: public Factory{
    Button CreateToLevelListButton();
    Button CreateNextLevelButton();
    Button CreateAgainButton();
};
