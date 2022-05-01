#pragma once
#include "Buttons.h"
#include "Label.h"
#include<string>
#include "Windows.h"

class Factory{
    //таких кнопок на странице не больше одной, так что координаты не нужны
    //все будет сразу прописано в дочерней фабрике
public:
    virtual void create_everything() =0;
    

//    virtual void CreateMenuButton(Button*) = 0;
//
//    virtual void CreateMorzeButton(Button *) =0;
//
//    virtual void CreateToLevelListButton(Button*) = 0;
//
//    virtual void CreateCheckButton(Button*) = 0;
//
//    virtual void CreateNextLevelButton(Button*) =0;
//
//    virtual void CreateAgainButton(Button*) =0;

    //этих кнопок на странице много - нужны координаты
//    virtual void CreateToLevelButtons(ToLevelButton*, int i) = 0;
//    virtual void CreateLetterButton(Button*, int x, int y, std::wstring*) =0;
};


class MenuFactory: public Factory{
public:
    MenuFactory() = default;
    std::tuple< create_everything() override;
    void CreateMorzeButton(Button*);//override;
    void CreateToLevelListButton(Button*);// override;
    void CreateLabel(Label*);
    void CreateLabelMorze(Label*);
};

class MorzeFactory: public Factory{
public:
    void CreateMenuButton(Button*);//override;
    void CreateMorzeAlphabet(Button*);
};

class LevelListFactory: public Factory{
public:
    void CreateMenuButton(Button*);//override;
    void CreateToLevelButtons(ToLevelButton*, int i);//override;
};

class GameProcessFactory: public Factory{
public:
    void CreateLabel(Label*, int level, int complexity);
    void CreateToLevelListButton(Button*);// override;
    void CreateCheckButton(Button*) ;//override;
    void CreateLetterButton(LetterButton*, int x, int y, std::wstring letter);
};

class GameCheckedFactory: public Factory{
public:
    void CreateToLevelListButton(Button*) ;//override;
    void CreateNextLevelButton(Button*);//override;
    void CreateAgainButton(Button*);//override;
    void CreateLetterButton(Button*, int x, int y, std::wstring& letter);
    void CreateLabel(Label*, int level, int complexity);

};
