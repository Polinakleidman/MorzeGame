#include "TransportButton.cpp"
#include "Lable.cpp"


//это интерфейс меню
class Menu{
public:
    sf::RenderWindow createMenuWindow();
    void addGreeting();
    WatchMorzeButton CreateMorzeButton();
    ToLevelListButton CreateToLevelListButton();
};


//это пример как будет реализова переход между окнами
//int main(){
//    Menu menu;
//    Aplhabet alphabet;
//    sf::renderwindow alphaberadress = alphabet.createAlphabetWindow;
//    sf::renderwindow menuadress = menu.createmunewind;
//    watchmorezebut but1 = menu.createmorzebut();
//    if (but1.isclicked()){
//        transport;
//    }
//}



//интерфейс азбуки
class Alphabet{
public:
    sf::RenderWindow createAlphabetWindow();
    void addPicture();
    void CreateBackToMenuButton();
};


//интефейс выбора уровня
class AllLevels{
public:
    sf::RenderWindow createAllLevelsWindow();
    void CreatelevelsButtons();
    void CreateOneLevelButton();
    void CreateBackToMenuButton();
};

//интерфейс играемого уровня
class GameProcess{
    sf::RenderWindow createLevelWindow();
    void CreatePhrase(Label phrase);
    void CreatePhraseWithButtons(Label phrase, int hardness);
    void CreateCheckButton();
    void CreateToLevelListButton();
};

//интерфейс проверенного уровня
class GameChecked{
    sf::RenderWindow createCheckedLevelWindow();
    void CreateColoredPhrase(Label phrase, std::vector<bool> correctLetters);
    void CreateAgainButton();
    void CreateNextButton();
    coid CreateToLevelListButton();
};