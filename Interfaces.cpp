#include "TransportButton.cpp"
#include "LetterButton.cpp"
#include "Label.cpp"


//это интерфейс меню
class Menu{
public:
    sf::RenderWindow& createMenuWindow();
    void addGreeting();
    WatchMorzeButton CreateMorzeButton();
    ToLevelListButton CreateToLevelListButton();
};


//интерфейс азбуки
class Alphabet{
public:
    sf::RenderWindow& createAlphabetWindow();
    void addPicture();
    BackToMenuButton CreateBackToMenuButton();
};

sf::RenderWindow& Alphabet::createAlphabetWindow() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");//для примера, с размерами мы еще не определились7
    return window;
}


//интефейс выбора уровня
class AllLevels{
public:
    sf::RenderWindow& createAllLevelsWindow();
    std::vector<ToLevelButton> CreatelevelsButtons();
    ToLevelButton CreateOneLevelButton();
    BackToMenuButton CreateBackToMenuButton();
};

//интерфейс играемого уровня
class GameProcess{
public:
    sf::RenderWindow& createLevelWindow();
    Label CreatePhrase(std::string phrase);
    std::vector<LetterButton> CreatePhraseWithButtons(Label phrase, int hardness);
    CheckButton CreateCheckButton();
    ToLevelListButton CreateToLevelListButton();
};

//интерфейс проверенного уровня
class GameChecked{
public:
    sf::RenderWindow& createCheckedLevelWindow();
    Label CreateColoredPhrase(std::string phrase, std::vector<bool> correctLetters);
    AgainButton CreateAgainButton();
    NextLevelButton CreateNextButton();
    ToLevelListButton CreateToLevelListButton();
};