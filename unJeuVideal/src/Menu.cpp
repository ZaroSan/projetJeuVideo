#include "Menu.h"
#include "Game.h"

#include <iostream>
#include <string>


using namespace sf;
using namespace std;

Menu::Menu()
{

}

int Menu::choix()
{

    Game ultimate_fantasy;
    int mouseX, mouseY;
    Image icon;

    string gameMode="Menu";

    vector<Personnage>allPersonnage;
    allPersonnage = initialisation();

    Team team1;
    Team team2;

    Sprite teamP1[2];
    Sprite teamP2[2];

    Text textButton;
    String choixJ="Joueur 1";

    RectangleShape button(Vector2f(220, 50));
    button.setFillColor(Color::Red);
    button.setPosition(700, 600);

    Sprite iPersonnage;
    Texture tex;

    Sprite Ipers[allPersonnage.size()];
    Texture Icon[allPersonnage.size()];

    for(unsigned int i=0; i<(allPersonnage.size()); i++)
    {
        if(!Icon[i].loadFromFile(PATH_IMAGE+ICON+allPersonnage[i].getName()+EXTENSION_IMAGE))
        {
            return -1;
        }
        else
        {
            Icon[i].setSmooth(true); //lisse l'icone pour les pixels
            Ipers[i].setTexture(Icon[i]);
            Ipers[i].setPosition(10+(80*(i%15)),300+50*(i/15));
        }
    }




    Font police;

    //création de la fenetre
    create(VideoMode(1200,700),"Ultimate Fantasy");
    sf::Text text, nomPers, text1, text2;
    nomPers.setFont(police);
    nomPers.setCharacterSize(24);
    text1.setFont(police);
    text1.setCharacterSize(24);
	text2.setFont(police);
	text2.setCharacterSize(24);
	text.setFont(police);
	text.setCharacterSize(24); // exprimée en pixels

	// choix de la couleur du texte
	textButton.setColor(sf::Color::White);
	text1.setColor(sf::Color::Black);
    text2.setColor(sf::Color::Black);
	text.setColor(sf::Color::Black);
    nomPers.setColor(sf::Color::Black);
	text.setPosition(100,160);
	text1.setPosition(100,580);
	text2.setPosition(100,650);
	nomPers.setPosition(100,220);


	text1.setString("Personnages du joueur 1");
	text2.setString("Personnages du joueur 2");
	text.setString("Au joueur 1 de choisir !");

    setFramerateLimit(60); //limiter à 60 fps

    if (!police.loadFromFile("Images/calibri.ttf"))
        {
            cout <<"Erreur lors du chargement de la police"<<endl;
            return -1;
        }


	while (this->isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            for(unsigned int j=0; j<(allPersonnage.size()); j++)
            {
                if(Ipers[j].getGlobalBounds().contains(Mouse::getPosition(*this).x,Mouse::getPosition(*this).y))
                {
                    nomPers.setString(allPersonnage[j].getName());
                }
            }
            switch (event.type)
            {
                case Event::Closed:      //si on ferme la fenetre
                    close();
                    break;
                case Event::KeyPressed:  //si on appuie sur la touche escape
                    if(event.key.code==Keyboard::Escape)
                        close();

                    break;

                case Event::MouseButtonPressed:
                    if(event.mouseButton.button==Mouse::Left)
                    {
                        mouseX=Mouse::getPosition(*this).x;            //on recupere la position de la souris
                        mouseY=Mouse::getPosition(*this).y;

                        if ((button.getGlobalBounds().contains(mouseX,mouseY))&& choixJ=="Fin")
                        {
                            text.setString("BOUTON");

                            close();

                            ultimate_fantasy.play(&team1,&team2);

                            return EXIT_SUCCESS;
                        }

                        for(unsigned int k=0;k<(allPersonnage.size());k++)
                        {
                            if(Ipers[k].getGlobalBounds().contains(mouseX, mouseY))
                            {
                                if(choixJ=="Joueur 1")
                                {
                                    if(findPersonnage(team1, allPersonnage[k])==false)
                                    {

                                        teamP1[team1.getListPersonnage().size()]=Ipers[k];
                                        teamP1[team1.getListPersonnage().size()].setPosition(400+(team1.getListPersonnage().size()*40),580);
                                        team1.AddPersonnage(allPersonnage[k]);

                                        text.setString("Personnage ajouté");

                                        if(team1.getListPersonnage().size()==2)
                                        {
                                            text.setString("Votre equipe est complete \n Choissisez l'équipe de l'IA !");
                                            choixJ="Joueur 2";
                                        }
                                    }

                                else
                                {
                                    text.setString("Ce personnage existe deja");
                                }
                            }
                            else
                            {
                                if(choixJ=="Joueur 2")
                                {
                                    if(findPersonnage(team2, allPersonnage[k])==false)
                                    {
                                        teamP2[team2.getListPersonnage().size()]=Ipers[k];
                                        teamP2[team2.getListPersonnage().size()].setPosition(400+(team2.getListPersonnage().size()*40),650);
                                        team2.AddPersonnage(allPersonnage[k]);

                                        text.setString("Personnage Ajoute");
                                        if(team2.getListPersonnage().size()==2)
                                        {
                                             text.setString("L'equipe est complete \n Appuyez sur le bouton pour lancer le combat");
                                             choixJ="Fin";
                                        }
                                    }
                                    else
                                    {
                                        text.setString("Ce personnage existe deja");
                                    }
                                }
                            }
                        }


                    }




                }
                break;
                default:
                    break;



            }

        }

/**************** Chargement et position Sprite **********/

         textButton.setString(" Passer au combat");
         textButton.setFont(police);
         textButton.setPosition(button.getPosition());

        clear(Color::White);               //affichages

        draw(text1);
        draw(text2);
        draw(nomPers);
        draw(text);
        draw(iPersonnage);

         if(choixJ=="Fin")
         {
           draw(button);
           draw(textButton);
         }

        for(unsigned int o=0;o<team1.getListPersonnage().size();o++)
        {
        draw(teamP1[o]);
        }
        for(unsigned int r=0;r<team1.getListPersonnage().size();r++)
        {
        draw(teamP2[r]);
        }



        for(unsigned int j=0;j<(allPersonnage.size());j++)
        {
        draw(Ipers[j]);
        }



        display();

    }

return EXIT_SUCCESS;

}

bool Menu::findPersonnage(Team t,Personnage p)
{
    for(unsigned int i=0;i<t.getListPersonnage().size();i++)
    {
        if(t.getListPersonnage()[i].getName()==p.getName())
        {
            return true;
        }
    }
return false;
}

vector<Personnage> Menu::initialisation()
{
    vector<Personnage>liste;


}

