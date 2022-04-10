#pragma once
#include "Buttons.h"
#include "Label.h"
#include<string>
class Factory{
    //таких кнопок на странице не больше одной, так что координаты не нужны
    //все будет сразу прописано в дочерней фабрике
public:
    void CreateMenuButton(Button&);
    void CreateMorzeButton(Button&);

    void CreateToLevelListButton(Button&);
    void CreateCheckButton(Button&);
    void CreateNextLevelButton(Button&);
    void CreateAgainButton(Button&);

    //этих кнопок на странице много - нужны координаты
    void CreateToLevelButtons(ToLevelButton&, int i);
    void CreateLetterButton(Button&, int x, int y, std::wstring&);
};

class MenuFactory: public Factory{
public:
    void CreateMorzeButton(Button&);
    void CreateToLevelListButton(Button&);
    void CreateLabel(Label&);
    void CreateLabelMorze(Label&);
};

class MorzeFactory: public Factory{
public:
    void CreateMenuButton(Button&);
    void CreateMorzeAlphabet(Button&);
};

class LevelListFactory: public Factory{
public:
    void CreateMenuButton(Button&);
    void CreateToLevelButtons(ToLevelButton&, int i);
};

class GameProcessFactory: public Factory{
public:
    void CreateLabel(Label&, int level, int complexity);
    void CreateToLevelListButton(Button&);
    void CreateCheckButton(Button&) ;
    void CreateLetterButton(LetterButton&, int x, int y, std::wstring& letter);
};

class GameCheckedFactory: public Factory{
    void CreateToLevelListButton(Button&);
    void CreateNextLevelButton(Button&);
    void CreateAgainButton(Button&);
};
