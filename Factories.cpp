#include"Factories.h"

 void MenuFactory::CreateMorzeButton(Button& MorzeButton) {

   //MorzeButton.set_all("G", 50, sf::Color::Red,
     //                   "../button.png", middle, middle, sf::Color::Blue, 200, 400,
     //                   100, 100);

     sf::Vector2<float> size(200, 200);
     MorzeButton.setSize(size);

     sf::Vector2<float> position(200, 200);
     MorzeButton.setPosition(position);

     sf::Text goToMorze("G", MorzeButton.font, 50);
     goToMorze.setFillColor({255, 0, 0, 100});
     MorzeButton.setText(goToMorze);

     sf::Texture MorzeTexture;
     MorzeTexture.loadFromFile("../button.png");
     MorzeButton.setTexture(MorzeTexture);

     MorzeButton.setTextPosition(middle, middle);




}

/*void MenuFactory::CreateToLevelListButton(Button& LevelListButton){

    LevelListButton.set_all("B", 50, sf::Color::Blue,
                        "../button.png", middle, middle, sf::Color::Red, 300, 300,
                        50, 50);
}*/

