#include "Menu.h"
#include "Game.h"
#include "Brawler.h"

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

    vector<Personnage> allPersonnage;
    vector<Mob> allMob;
    allPersonnage=initialisation();
    allMob=initialisationEnnemy();

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
    Sprite iMob;
    Texture tex;

    Sprite Ipers[allPersonnage.size()];
    Sprite Imob[allMob.size()];
    Texture Icon[allPersonnage.size()];
    Texture IconMob[allMob.size()];

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

    for(unsigned int j=0; j<(allMob.size()); j++)
    {
        if(!IconMob[j].loadFromFile(PATH_IMAGE+_ICON+allMob[j].getName()+EXTENSION_IMAGE)) //charge l'icone du mob
        {
            cout <<"Erreur lors du chargement de allMob dans menu"<<endl;
            return -1;
        }
        else
        {
            IconMob[j].setSmooth(true); //lisse l'icone pour les pixels
            Imob[j].setTexture(IconMob[j]);
            Imob[j].setPosition(330+(80*(j%15)),300+50*(j/15));
        }
    }




    Font police;


    //création de la fenetre
    create(VideoMode(1200,700),"Ultimate Fantasy");
    sf::Text text, nomPers,nomMob, text1, text2;
    nomPers.setFont(police);
    nomPers.setCharacterSize(24);
    nomMob.setFont(police);
    nomMob.setCharacterSize(24);
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
    nomMob.setColor(sf::Color::Black);
	text.setPosition(100,160);
	text1.setPosition(100,580);
	text2.setPosition(100,650);
	nomPers.setPosition(100,220);
	nomMob.setPosition(300,220);


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
            for(unsigned int n=0; n<(allMob.size()); n++)
            {
                if(Imob[n].getGlobalBounds().contains(Mouse::getPosition(*this).x,Mouse::getPosition(*this).y))
                {
                    nomMob.setString(allMob[n].getName());
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

                            close(); //ferme la fenetre et réouvre la suivante via la methode play()

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

                                }else
                                {
                                    text.setString("Ce personnage existe deja");
                                }
                            }
                        }



                        for(unsigned int l=0;l<(allMob.size());l++)
                        {
                            if(Imob[l].getGlobalBounds().contains(mouseX, mouseY))
                            {
                                if(choixJ=="Joueur 2")
                                {
                                    if(findMob(team2, allMob[l])==false)
                                    {

                                        teamP2[team2.getListMob().size()]=Imob[l];
                                        teamP2[team2.getListMob().size()].setPosition(400+(team1.getListMob().size()*40),650);
                                        team2.AddMob(allMob[l]);

                                        text.setString("Mob ajouté");

                                        if(team2.getListMob().size()==2)
                                        {
                                             text.setString("Votre equipe est complete \n Appuyez sur le bouton pour lancer le combat");
                                             choixJ="Fin";
                                        }
                                    }

                                }else
                                {
                                    text.setString("Ce Mob existe deja");
                                }
                            }
                        }

//

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
        draw(nomMob);

        draw(text);
        draw(iPersonnage);
        draw(iMob);

         if(choixJ=="Fin")
         {
           draw(button);
           draw(textButton);
         }

        for(unsigned int o=0;o<team1.getListPersonnage().size();o++)
        {
        draw(teamP1[o]);
        }
        for(unsigned int r=0;r<team2.getListMob().size();r++)
        {
        draw(teamP2[r]);
        }


        for(unsigned int j=0;j<(allPersonnage.size());j++)
        {
        draw(Ipers[j]);
        }

        for(unsigned int h=0;h<(allMob.size());h++)
        {
        draw(Imob[h]);
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

bool Menu::findMob(Team t,Mob m)
{
    for(unsigned int j=0;j<t.getListMob().size();j++)
    {
        if(t.getListMob()[j].getName()==m.getName())
        {
            return true;
        }
    }
return false;
}


vector<Personnage> Menu::initialisation()
{
    vector<Personnage>liste;
    //creation d'attaque avec les différentes stats
    //string name, int power, int mana, int manaFix
    // => important à modifier les attribut, add force

    Attack Fury_Charge("Fury Charge", 100, 50, 30);
    Attack Focus_Blast("Focus Blast", 100, 50, 30);
    Attack Full_Counter("Full Counter", 100, 50, 30);
    Attack Outrage("Outrage", 100, 50, 30);

    Attack Perfect_Shot("Perfect Shot", 100, 50, 30);
    Attack Multiple_Shots("Multiple Shots", 100, 50, 30);
    Attack Sharp_Dagger("Sharp Dagger", 100, 50, 30);
    Attack Fire_Arrow("Fire Arrow", 100, 50, 30);

    Attack Group_Care("Group Care", 100, 50, 30);
    Attack Heal("Heal", 100, 50, 30);
    Attack Resurrection("Resurrection", 100, 50, 30);
    Attack Panacea("Panacea", 100, 50, 30);

    Attack Blizzard("Blizzard", 100, 50, 30);
    Attack Lightning_Impact("Lightning Impact", 100, 50, 30);
    Attack Heat_Wave("Heat Wave", 100, 50, 30);
    Attack Explosion("Explosion", 100, 50, 30);



    Attack attackBrawl[4]={Fury_Charge, Focus_Blast, Full_Counter, Outrage};
    Attack attackRanger[4]={Perfect_Shot, Multiple_Shots, Sharp_Dagger, Fire_Arrow};
    Attack attackHealer[4]={Group_Care, Heal, Resurrection, Panacea};
    Attack attackWizard[4]={Blizzard, Lightning_Impact, Heat_Wave, Explosion};

    //creation personnage
    //string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor, Attack* attack
    Personnage brawler("Brawler",10,10,10,10,10,attackBrawl);
    Personnage ranger("Ranger",10,10,10,10,10,attackBrawl);
    Personnage healer("Healer",10,10,10,10,10,attackHealer);
    Personnage wizard("Wizard",10,10,10,10,10,attackWizard);

   // brawler.affiche();


    //ajout à la liste
	liste.push_back(brawler);
	liste.push_back(ranger);
	liste.push_back(healer);
	liste.push_back(wizard);



    return liste;




}


vector<Mob>Menu::initialisationEnnemy()
{
    vector<Mob>liste;

    Attack Masse_Os("Masse Os", 100, 50, 30);
    Attack Coup_De_Crane("Coup de crane", 100, 50, 30);
    Attack Tibia_Long("Tibia long", 100, 50, 30);
    Attack Phalange("Phalange", 100, 50, 30);

    Attack Coup_De_Kanabo("Coup de Kanabo", 100, 50, 30);
    Attack poing_Geant("Poing geant", 100, 50, 30);
    Attack Grande_frappe("Grande frappe", 100, 50, 30);
    Attack Behemoth_Bullet("Behemoth Bullet", 100, 50, 30);

    Attack True_Dark("True Dark", 100, 50, 30);
    Attack Beautiful_Snow("Beautiful Snow", 100, 50, 30);
    Attack Bubble_Push("Bubble Push", 100, 50, 30);
    Attack Terror_Thrust("Terror Thrust", 100, 50, 30);

    Attack attackSkeleton[4]={Masse_Os, Coup_De_Crane, Tibia_Long, Phalange};
    Attack attackOrc[4]={Coup_De_Kanabo, poing_Geant, Grande_frappe, Behemoth_Bullet};
    Attack attackElf[4]={True_Dark, Beautiful_Snow, Bubble_Push, Terror_Thrust};

    Mob skeleton("Skeleton", 10,10,10,10,10,attackSkeleton);
    Mob orc("Orc",10,10,10,10,10,attackOrc);
    Mob elf("Elf",10,10,10,10,10,attackElf);



    liste.push_back(skeleton);
    liste.push_back(orc);
    liste.push_back(elf);

    return liste;


}

