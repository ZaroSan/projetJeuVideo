#include "Menu.h"
#include "Game.h"

#include <iostream>
#include <string>


using namespace sf;

Menu::Menu()
{

}

int Menu::choix()
{
    /*
    Game game_battleRound;
    int mouseX, mouseY;
    Image icon;

    vector<FactoryCharacter>allCharater;
    allCharater = initialize();

    Team team1;
    Team team2;

    Sprite TeamP1[2];
    Sprite TeamP2[2];

    Text textButton;
    String choixJ="Joueur 1";

    RectangleShape button(Vector2f(220, 50);
    button.setFillColor(Color::Red);
    button.setPosition(700, 600);

    Sprite iCharacter;
    Texture tex;

    Sprite Icha[allCharater.size()];
    Texture Icon[allCharater.size()];



*/
    Font police;

    //création de la fenetre
    create(VideoMode(1200,700),"Ultimate Fantasy");
    sf::Text text, nomCharacter, text1, text2;
    nomCharacter.setFont(police);
    nomCharacter.setCharacterSize(24);
    text1.setFont(police);
    text1.setCharacterSize(24);
	text2.setFont(police);
	text2.setCharacterSize(24);
	text.setFont(police);
	text.setCharacterSize(24); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
//	textButton.setColor(sf::Color::White);
	text1.setColor(sf::Color::Black);
    text2.setColor(sf::Color::Black);
	text.setColor(sf::Color::Black);
    nomCharacter.setColor(sf::Color::Black);
	text.setPosition(100,160);
	text1.setPosition(100,580);
	text2.setPosition(100,650);
	nomCharacter.setPosition(100,220);



	while (this->isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                close();
        }

       // window.clear();
      //  window.draw(shape);
          display();
    }



}

