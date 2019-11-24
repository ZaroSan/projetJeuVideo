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

    vector<Personnage> allPersonnage;  //liste de personnages
    allPersonnage=initialisation(); 

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
        if(!Icon[i].loadFromFile(PATH_IMAGE+_ICON+allPersonnage[i].getName()+EXTENSION_IMAGE)) //charge l'icone du personnage
        {
            cout <<"Erreur lors du chargement dans menu allperso"<<endl;
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


    //cr�ation de la fenetre
    create(VideoMode(1200,700),"Ultimate Fantasy", sf::Style::Close);
    sf::Text text, nomPers, text1, text2;
    nomPers.setFont(police);
    nomPers.setCharacterSize(24);
    text1.setFont(police);
    text1.setCharacterSize(24);
	text2.setFont(police);
	text2.setCharacterSize(24);
	text.setFont(police);
	text.setCharacterSize(24); // exprim�e en pixels

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

    setFramerateLimit(60); //limiter � 60 fps

    if (!police.loadFromFile("Images/calibri.ttf"))
        {
            cout <<"Erreur lors du chargement de la police"<<endl;
            return -1;
        }




	while (this->isOpen())
    {
        sf::Event event;
        while (pollEvent(event)){                             //boucle des evenements

          for (unsigned int t=0;t<(allPersonnage.size());t++)
          {
            if(Ipers[t].getGlobalBounds().contains(Mouse::getPosition(*this).x,Mouse::getPosition(*this).y))
            {
                nomPers.setString(allPersonnage[t].getName()); //nom au dessus des perso
            }
          }
            switch (event.type){

                case Event::Closed:                                 //si on ferme la fenetre
                    close();

                    break;

                case Event::KeyPressed:                             //si on appuie sur une touche

                    if (event.key.code==Keyboard::Escape)
                       close();

                    break;

                case Event::MouseButtonPressed:
                     if (event.mouseButton.button==Mouse::Left){             //bouton gauche
                            mouseX=Mouse::getPosition(*this).x;            //on recupere la position de la souris
                            mouseY=Mouse::getPosition(*this).y;

                             if ((button.getGlobalBounds().contains(mouseX,mouseY))&& choixJ=="Fin")
                             {
                                text.setString("BOUTON");

								close();

                                ultimate_fantasy.play(&team1, &team2); //dans cette boucle on appelle la méthode play de Game.cpp qui cntient une fenetre
                                                                        // et on ferme cette fenetre

                                return EXIT_SUCCESS;
                             }

                            for (unsigned int k=0;k<(allPersonnage.size());k++)
                            {
                                if (Ipers[k].getGlobalBounds().contains(mouseX,mouseY))
                                {
                                   if(choixJ=="Joueur 1")
                                   {
                                    //ajout du perso dans la team1
                                    if(findPersonnage(team1,allPersonnage[k])==false)
                                    {
                                        teamP1[team1.getListPersonnage().size()]=Ipers[k];
                                        teamP1[team1.getListPersonnage().size()].setPosition(400+(team1.getListPersonnage().size()*40),580);
                                        team1.AddPersonnage(allPersonnage[k]);

                                        text.setString("Personnage Ajoute");
                                        //si la team1 = 2 perso, on passe à la team2
                                        if(team1.getListPersonnage().size()==2)
                                        {
                                             text.setString("Votre equipe est complete \n Au joueur 2 de chosir");
                                             choixJ="Joueur 2";

                                        }
                                      }
                                        else //impossible de prendre deux fois le meme perso par equipe
                                        {
                                          text.setString("Ce Personnage existe deja");
                                        }
                                   }
                                   else
                                   {
                                       if(choixJ=="Joueur 2")
                                       {
                                            //ajout du perso dans la team2
                                         if(findPersonnage(team2,allPersonnage[k])==false)
                                        {
                                        teamP2[team2.getListPersonnage().size()]=Ipers[k];
                                        teamP2[team2.getListPersonnage().size()].setPosition(400+(team2.getListPersonnage().size()*40),650);
                                        team2.AddPersonnage(allPersonnage[k]);

                                        text.setString("Personnage Ajoute");
                                        //verification de la taille de l'équipe
                                        if(team2.getListPersonnage().size()==2)
                                        {
                                             text.setString("Votre equipe est complete \n Appuyez sur le bouton pour lancer le combat");
                                             choixJ="Fin";
                                        }
                                        }
                                        else
                                        {
                                          text.setString("Ce Personnage existe deja");
                                        }
                                    }
                                   }
                                }
                            }
                            }                       //si on clique
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
        //dessine les icones des différents perso de chaque equipes
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
    //creation d'attaque avec les diff�rentes stats
    //string name, int power, int mana, int precision

    Attack Fury_Charge("Fury Charge", 100, 10, 80);
    Attack Focus_Blast("Focus Blast", 40, 15, 90);
    Attack Full_Counter("Full Counter", 75, 10, 100);
    Attack Outrage("Outrage", 60, 15, 80);

    Attack Perfect_Shot("Perfect Shot", 85, 5, 120);
    Attack Multiple_Shots("Multiple Shots", 65, 15, 100);
    Attack Sharp_Dagger("Sharp Dagger", 70, 15, 100);
    Attack Fire_Arrow("Fire Arrow", 100, 5, 120);

    Attack Group_Care("Group Care", 55, 10, 60);
    Attack Flower_Power("Flower Power", 65, 10, 60);
    Attack Soul_Power("Soul Power", 65, 10, 60);
    Attack Panacea("Panacea", 100, 10, 60);

    Attack Blizzard("Blizzard", 100, 10, 100);
    Attack Lightning_Impact("Lightning Impact", 100, 15, 90);
    Attack Heat_Wave("Heat Wave", 55, 50, 70);
    Attack Explosion("Explosion", 120, 1, 50);



    Attack attackBrawl[4]={Fury_Charge, Focus_Blast, Full_Counter, Outrage};
    Attack attackRanger[4]={Perfect_Shot, Multiple_Shots, Sharp_Dagger, Fire_Arrow};
    Attack attackHealer[4]={Group_Care, Flower_Power, Soul_Power, Panacea};
    Attack attackWizard[4]={Blizzard, Lightning_Impact, Heat_Wave, Explosion};


    //creation personnage
    //string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor,int speed, Attack* attack
    Personnage brawler("Brawler", 350, 100, 15, 80, 75,55,attackBrawl);
    Personnage ranger("Ranger",278,95,15,50,50,100,attackRanger);
    Personnage healer("Healer",150,50,90,30,30,45,attackHealer);
    Personnage wizard("Wizard",275,45,100,30,30,75,attackWizard);

  //  cout<<"je suis un  tetst = "<<brawler.getAttack()->getName()<<endl;


    //ajout � la liste
	liste.push_back(brawler);
	liste.push_back(ranger);
	liste.push_back(healer);
	liste.push_back(wizard);





	Attack Masse_Os("Masse Os", 100, 15, 100);
    Attack Coup_De_Crane("Coup de crane", 75, 10, 75);
    Attack Tibia_Long("Tibia long", 55, 15, 65);
    Attack Phalange("Phalange", 30, 15, 25);

    Attack Coup_De_Kanabo("Coup de Kanabo", 85, 15, 95);
    Attack poing_Geant("Poing geant", 100, 15, 100);
    Attack Grande_frappe("Grande frappe", 60, 15, 75);
    Attack Behemoth_Bullet("Behemoth Bullet", 85, 15, 55);

    Attack True_Dark("True Dark", 100, 15, 100);
    Attack Beautiful_Snow("Beautiful Snow", 65, 15, 66);
    Attack Bubble_Push("Bubble Push", 55, 15, 55);
    Attack Terror_Thrust("Terror Thrust", 100, 15, 100);

    Attack attackSkeleton[4]={Masse_Os, Coup_De_Crane, Tibia_Long, Phalange};
    Attack attackOrc[4]={Coup_De_Kanabo, poing_Geant, Grande_frappe, Behemoth_Bullet};
    Attack attackElf[4]={True_Dark, Beautiful_Snow, Bubble_Push, Terror_Thrust};


    //creation personnage
    //string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor, int speed, Attack* attack
    Personnage skeleton("Skeleton", 300,60,60,30,30,60,attackSkeleton);
    Personnage orc("Orc",325,100,30,65,65,50,attackOrc);
    Personnage elf("Elf",275,50,100,50,50,60,attackElf);



    liste.push_back(skeleton);
    liste.push_back(orc);
    liste.push_back(elf);



    return liste;




}


