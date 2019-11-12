#include "Game.h"
#include "Team.h"

#include <iostream>
#include <string>
#include <stdio.h>

using namespace sf;
using namespace std;

Game::Game()
{
    //ctor
}

int Game::play(Team* team1, Team* team2)
{
    int mouseX, mouseY;
    int nbTour=1;
    int randAtt;
    int randPers;
    bool riposter = false;

    Personnage J1;   //Les 2 persos en combat
    Personnage J2;

    Font police;

    Text nomLanceur, nomEnnemi, nomAttaque1,nomAttaque2,nomAttaque3,nomAttaque4,pvLanceur,pvEnnemi;

    Texture fond;
    Sprite lanceur;
    Sprite ennemi;

    Sprite iPers[2];
    RectangleShape PersonnageSwitch[2];

    Texture textIcone[2];

    Image icone;

    RectangleShape fond_ecran;

    RectangleShape barreVieLanceur(Vector2f(200,20));
    RectangleShape barreVieEnnemi(Vector2f(200,20));

    RectangleShape barreVieLanceurBord(Vector2f(204,24));
    RectangleShape barreVieEnnemiBord(Vector2f(204,24));

    RectangleShape attaque1(Vector2f(150,50));
    RectangleShape attaque2(Vector2f(150,50));
    RectangleShape attaque3(Vector2f(150,50));
    RectangleShape attaque4(Vector2f(150,50));

	RectangleShape afficheText(Vector2f(800,200));

	Text nomIcone[6];

    Text text;

    Text tour;

    string script="";

    Event event;

    srand(time(0));

    create(VideoMode(1200,700),"Ultimate Fantasy");


    attaque1.setFillColor(Color::Blue);
    attaque2.setFillColor(Color::Blue);
    attaque3.setFillColor(Color::Blue);
    attaque4.setFillColor(Color::Blue);
    afficheText.setFillColor(Color::White);

    attaque1.setPosition(0,getSize().y-50);
    attaque2.setPosition(200,getSize().y-50);
    attaque3.setPosition(400,getSize().y-50);
    attaque4.setPosition(600,getSize().y-50);

    afficheText.setPosition(0,getSize().y-280);

    PersonnageSwitch[0].setPosition(900,getSize().y-170);
    PersonnageSwitch[1].setPosition(1100,getSize().y-170);

    for(int i=0; i<2;i++)
    {
        nomIcone[i].setPosition(PersonnageSwitch[i].getPosition().x+50,PersonnageSwitch[i].getPosition().y);
    }

    text.setFont(police);

	tour.setFont(police);
	tour.setPosition(0,0);

	text.setColor(sf::Color::Black);

	text.setPosition(5,getSize().y-260);
	text.setCharacterSize(15);

	J1=team1->getListPersonnage()[0];
	J2=team2->getListPersonnage()[0];

	script=("BATTLE\nJ1 envoie "+J1.getName()+" !\nJ2 envoie "+J2.getName()+" !\n");
    setFramerateLimit(60);

    if (!fond.loadFromFile("Images/landscape.jpeg"))
        return -1;

    if (!police.loadFromFile("Images/calibri.ttf"))
             return -1;

    fond_ecran.setSize(Vector2f(getSize().x,getSize().y));
    fond_ecran.setTexture(&fond);
    fond_ecran.setPosition(0,0);


    while(this->isOpen()){
        randAtt=rand()%4;

        while(pollEvent(event)){
            switch(event.type){
                case Event::Closed:    //si on ferme la fenetre
                    close();

                    break;

                 case Event::KeyPressed:                             //si on appuie sur une touche

                    if (event.key.code==Keyboard::Escape)
                        close();

                    break;

/****************************************Gestion du clic sur les boutons***************************************************/

                case Event::MouseButtonPressed:                        //si on clique

                    if (event.mouseButton.button==Mouse::Left){             //bouton gauche
                       mouseX=Mouse::getPosition(*this).x;            //on recupere la position de la souris
                       mouseY=Mouse::getPosition(*this).y;

                       if(!J1.estKO()){
                        /***********************************Attaques ***************************/
                            if (attaque1.getGlobalBounds().contains(mouseX,mouseY)){        //si on clique sur les boutons d'attaque
                                    if(J1.getAttack()[0].getMana()>0){
                                       /*if(J1.getSpeed()>=J2.getSpeed())
                                        {
                                                script=J1.

                                        }*/
                                    }
                       }




            }
        }
    }

    }











    }






return EXIT_SUCCESS;

}

