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
    int randEnnemy;
    bool riposter = false;

    Personnage J1;   //Les 2 persos en combat
    Mob J2;

    Font police;

    Text nomLanceur, nomEnnemi, nomAttaque1,nomAttaque2,nomAttaque3,nomAttaque4,pvLanceur,pvEnnemi;



    Texture fond, p1, p2;  //texture fond + perso 1...
    Sprite lanceur;
    Sprite ennemi;

    Sprite iPers[2];
    Sprite iMob[2];
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

    create(VideoMode(1200,700),"Ultimate Fantasy"); //creation de la fenetre


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
	J2=team2->getListMob()[0];

	script=("BATTLE\nJ1 envoie "+J1.getName()+" !\nJ2 envoie "+J2.getName()+" !\n");
    setFramerateLimit(60);

    if (!fond.loadFromFile("Images/landscape.jpeg")){
        cout <<"Erreur lors du chargement de landscape"<<endl;
        return -1;
    }

    if (!police.loadFromFile("Images/calibri.ttf")){
        cout <<"Erreur lors du chargement de calibri"<<endl;
        return -1;
    }

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
                                       if(J1.getSpeed()>=J2.getSpeed())
                                        {
                                                script=J1.lancerAttaque(J1.getAttack()[0],&J1, J2 );

                                                if(!J2.estKO())
                                                {
                                                    script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 );
                                                }

                                        }
                                        else{
                                            script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 );

                                            if(!J1.estKO())
                                            {
                                                script=J1.lancerAttaque(J1.getAttack()[0],&J1, J2 );
                                            }
                                        }

                                        J1.getAttack()[0].setMana(J1.getAttack()[0].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbTour ++;

                                    }
                                    else{

                                        J1.getAttack()[0].setMana(0);
                                        script="Plus de Mana";
                                    }
                       }

                       if(attaque2.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[1].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.lancerAttaque(J1.getAttack()[1],&J1, J2 )+"\n";

                                    if(!J2.estKO())
                                    {
                                        script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";
                                    }

                                }else{
                                    script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";

                                    if(!J1.estKO())
                                    {
                                        script=J1.lancerAttaque(J1.getAttack()[1],&J1, J2 );
                                    }
                                }
                                        J1.getAttack()[1].setMana(J1.getAttack()[1].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbTour ++;

                                    }
                                    else{

                                        J1.getAttack()[1].setMana(0);
                                        script="Plus de Mana";
                                    }
                           }

                       if(attaque3.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[2].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.lancerAttaque(J1.getAttack()[2],&J1, J2 )+"\n";

                                    if(!J2.estKO())
                                    {
                                        script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";
                                    }

                                }else{
                                    script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";

                                    if(!J1.estKO())
                                    {
                                        script=J1.lancerAttaque(J1.getAttack()[2],&J1, J2 );
                                    }
                                }
                                        J1.getAttack()[2].setMana(J1.getAttack()[2].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbTour ++;

                                    }
                                    else{

                                        J1.getAttack()[2].setMana(0);
                                        script="Plus de Mana";
                                    }
                           }

                       if(attaque4.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[3].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.lancerAttaque(J1.getAttack()[3],&J1, J2 )+"\n";

                                    if(!J2.estKO())
                                    {
                                        script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";
                                    }

                                }else{
                                    script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";

                                    if(!J1.estKO())
                                    {
                                        script=J1.lancerAttaque(J1.getAttack()[3],&J1, J2 );
                                    }
                                }
                                        J1.getAttack()[3].setMana(J1.getAttack()[3].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbTour ++;

                                    }
                                    else{

                                        J1.getAttack()[3].setMana(0);
                                        script="Plus de Mana";
                                    }
                           }

                       }
                       else
                       {
                          script=J1.getName()+" est KO !";
                       }

    /*************************************************************Gestion du switch ******************************************/

                    for(unsigned int i=0;i<team1->getListPersonnage().size();i++)
                    {
                        if(PersonnageSwitch[i].getGlobalBounds().contains(mouseX, mouseY))
                        {
                            if(!J1.estKO())
                            {
                                riposter = true;
                            }

                            if(team1->getListPersonnage()[i].getName()==J1.getName())
                            {
                                script = J1.getName()+" est d�j� en combat ! \n";
                            }
                            else{

                                script=J1.getName()+" est retir� par le joueur !\n";
                                script+="Le joueur envoie "+team1->getListPersonnage()[i].getName()+" !\n";

                                for(unsigned int j=0;j<team1->getListPersonnage().size();j++){
                                        if (team1->getListPersonnage()[j].getName()==J1.getName()){      //on cherche l'ancien perso dans la liste
                                            team1->removePersonnage(j);                                 //on le supprime
                                            team1->insertPersonnage(J1,j);                              //on met � jour le personnage avant le switch
                                        }
                                    }

                                J1=team1->getListPersonnage()[i];

                                if(!p1.loadFromFile(J1.getPath(true)))
                                {
                                    return -1;
                                }

                                lanceur.setScale(1,1);
                                barreVieLanceur.setScale(1,1);
                                barreVieLanceurBord.setScale(1,1);
                                pvLanceur.setScale(1,1);
                                nomLanceur.setScale(1,1);


                                if (riposter)
                                {                                                  //si on switche sans etre KO, l'ennemi attaque quand meme
                                    riposter=false;
                                    script+=J2.lancerAttaque(J2.getAttack()[randAtt],J1, &J2 )+"\n";
                                    J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);
                                    nbTour++;
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

    /**************************************Gestion des KO pour joueur ennemi****************************************/

    if(J2.estKO())
    {
        if(team2->isEmptyEnnemy())
        {
            ennemi.setScale(0,0);
            barreVieEnnemi.setScale(0,0);
            barreVieEnnemiBord.setScale(0,0);
            pvEnnemi.setScale(0,0);
            nomEnnemi.setScale(0,0);


            script="\n L'ennemi � perdu !\n";
        }else
        {
            for(unsigned int i=0;i<team2->getListMob().size();i++)
            {
                if(team2->getListMob()[i].getName()==J2.getName())
                {
                    team2->removeMob(i); //suppresion du l'ennemi dans la liste
                }
            }

            for(unsigned int i=0; i<team2->getListMob().size(); i++)
            {
                randEnnemy=rand()%(team2->getListMob().size());
                {
                    J2=team2->getListMob()[randEnnemy];
                }
            }

            script+="\n L'ennemi "+J2.getName()+" apparait sur le terrain !\n";

        }
    }

    /**************************************Gestion des KO pour joueur ****************************************/

    if(J1.estKO())
    {

        lanceur.setScale(0,0);
        barreVieLanceur.setScale(0,0);
        barreVieLanceurBord.setScale(0,0);
        pvLanceur.setScale(0,0);
        nomLanceur.setScale(0,0);

        if(team1->isEmpty())
        {
            script="\n Le joueur � perdu !";
        }else
        {
            for(unsigned int i=0;i<team1->getListPersonnage().size();i++)
            {
                if(team1->getListPersonnage()[i].getName()==J1.getName())
                {
                    team1->removePersonnage(i); //suppresion du personnage dans la liste
                }
            }

        }
    }

    /**************************************Chargement et position du sprite ****************************************/

    if (!p1.loadFromFile(J1.getPath(false),IntRect(150,200,0,0))){// Si le chargement du fichier a �chou�

        cout<<"je suis un tets : "+p1.loadFromFile(J1.getPath(false))<<endl;
                  return -1; // On ferme le programme
    }else{
        p1.setSmooth(true);
        lanceur.setTexture(p1);
        lanceur.setTextureRect(IntRect(0,0,150, 200));
        lanceur.setPosition(0, getSize().y-450);
    }



     if (!p2.loadFromFile(J2.getPath(true),IntRect(150,200,0,0)))
    {
        return -1;
    }else
    {
        p2.setSmooth(true);
        ennemi.setTexture(p2);
        ennemi.setTextureRect(IntRect(0,0,150,200));
        ennemi.setPosition(getSize().x-300,getSize().y-450);
    }


    /**************************************Icone et bouton switch ****************************************/

    for(unsigned int i=0;i<team1->getListPersonnage().size();i++)
    {
        if(!textIcone[i].loadFromFile(PATH_IMAGE+ICON+team1->getListPersonnage()[i].getName()+EXTENSION_IMAGE))
        {
            cout <<"Erreur lors du chargement de getlistperso"<<endl;
            return -1;
        }else{
            textIcone[i].setSmooth(true);
            iPers[i].setTexture(textIcone[i]);
            iPers[i].setPosition(PersonnageSwitch[i].getPosition().x+5, PersonnageSwitch[i].getPosition().y+5);
        }

        PersonnageSwitch[i].setSize(Vector2f(140, 150));
        nomIcone[i].setFont(police);
        nomIcone[i].setString(team1->getListPersonnage()[i].getName());
        nomIcone[i].setColor(Color::Black);
        nomIcone[i].setScale(0.5, 0.5);

    }


    for(unsigned int j=0;j<team2->getListMob().size();j++)
    {
        if(!textIcone[j].loadFromFile(PATH_IMAGE+ICON+team2->getListMob()[j].getName()+EXTENSION_IMAGE))
        {
            cout <<"Erreur lors du chargement de getlistMob"<<endl;
            return -1;
        }else{
            textIcone[j].setSmooth(true);
            iMob[j].setTexture(textIcone[j]);
            //iMob[i].setPosition(PersonnageSwitch[i].getPosition().x+5, PersonnageSwitch[i].getPosition().y+5);
        }

       // PersonnageSwitch[i].setSize(Vector2f(140, 150));
        nomIcone[j].setFont(police);
        nomIcone[j].setString(team2->getListMob()[j].getName());
        nomIcone[j].setColor(Color::Black);
        nomIcone[j].setScale(0.5, 0.5);

    }


    /**************************************Position et tailles des boutons/textes ****************************************/

        barreVieLanceur.setPosition(lanceur.getPosition().x+lanceur.getTextureRect().width,(lanceur.getPosition().y+lanceur.getTextureRect().height/4)-100);
        barreVieEnnemi.setPosition(ennemi.getPosition().x-ennemi.getTextureRect().width-150,(ennemi.getPosition().y+ennemi.getTextureRect().height/4)-100);

        barreVieLanceurBord.setPosition(barreVieLanceur.getPosition().x-2,barreVieLanceur.getPosition().y-2);
        barreVieEnnemiBord.setPosition(barreVieEnnemi.getPosition().x-2,barreVieEnnemi.getPosition().y-2);

        barreVieLanceurBord.setOutlineColor(Color::Black);
        barreVieEnnemiBord.setOutlineColor(Color::Black);

        nomLanceur.setString(J1.getName());
        nomLanceur.setFont(police);
        nomLanceur.setColor(Color::Red);
        nomLanceur.setPosition(lanceur.getPosition().x+lanceur.getTextureRect().width,lanceur.getPosition().y-100);

        nomEnnemi.setString(J2.getName());
        nomEnnemi.setFont(police);
        nomEnnemi.setColor(Color::Blue);
        nomEnnemi.setPosition(barreVieEnnemi.getPosition().x,barreVieEnnemi.getPosition().y-42);

        nomAttaque1.setString(J1.getAttack()[0].getName());
        nomAttaque1.setFont(police);
        nomAttaque1.setPosition(attaque1.getPosition());
        nomAttaque1.setScale(0.75, 0.75);

        nomAttaque2.setString(J1.getAttack()[1].getName());
        nomAttaque2.setFont(police);
        nomAttaque2.setPosition(attaque1.getPosition());
        nomAttaque2.setScale(0.75, 0.75);

        nomAttaque3.setString(J1.getAttack()[2].getName());
        nomAttaque3.setFont(police);
        nomAttaque3.setPosition(attaque1.getPosition());
        nomAttaque3.setScale(0.75, 0.75);

        nomAttaque4.setString(J1.getAttack()[3].getName());
        nomAttaque4.setFont(police);
        nomAttaque4.setPosition(attaque1.getPosition());
        nomAttaque4.setScale(0.75, 0.75);

        //point de vie en fonction des degats

        if((100*J1.getLifePoint()/J1.getLifePointMax()) >=50)
        {
            barreVieLanceur.setFillColor(Color::Green);

        }else if((100*J1.getLifePoint()/J1.getLifePointMax()) >=20){
            barreVieLanceur.setFillColor(Color::Yellow);

        }else{
            barreVieLanceur.setFillColor(Color::Red);
        }


        if((100*J2.getLifePoint()/J2.getLifePointMax()) >=50)
        {
            barreVieEnnemi.setFillColor(Color::Green);

        }else if((100*J2.getLifePoint()/J2.getLifePointMax()) >=20){
            barreVieEnnemi.setFillColor(Color::Yellow);

        }else{
            barreVieEnnemi.setFillColor(Color::Red);
        }


        text.setString(script);
        tour.setString("Tour : "+Personnage::toString(nbTour)+"Personnages restants: "+Mob::toString((int)team2->getListMob().size()));

        barreVieLanceur.setSize(Vector2f((J1.getLifePoint()*200)/J1.getLifePointMax(),20));
        barreVieEnnemi.setSize(Vector2f((J2.getLifePoint()*200)/J2.getLifePointMax(),20));

        pvLanceur.setFont(police);
        pvLanceur.setString(Personnage::toString(100*J1.getLifePoint()/J1.getLifePointMax())+"%");
        pvLanceur.setPosition(barreVieLanceur.getPosition().x+barreVieLanceur.getSize().x-pvLanceur.getGlobalBounds().width,barreVieLanceur.getPosition().y);
        pvLanceur.setCharacterSize(18);
        pvLanceur.setColor(Color::Black);


        pvEnnemi.setFont(police);
        pvEnnemi.setString(Mob::toString(100*J2.getLifePoint()/J2.getLifePointMax())+"%");
        pvEnnemi.setPosition(barreVieEnnemi.getPosition().x+barreVieEnnemi.getSize().x-pvEnnemi.getGlobalBounds().width,barreVieEnnemi.getPosition().y);
        pvEnnemi.setCharacterSize(18);
        pvEnnemi.setColor(Color::Black);


        /**********************Affichages*******************/

        clear(Color::White);

        draw(fond_ecran);

        draw(afficheText);

        draw(lanceur);
        draw(ennemi);

        draw(barreVieLanceur);
        draw(barreVieEnnemi);

        draw(barreVieLanceurBord);
        draw(barreVieEnnemiBord);

        draw(attaque1);
        draw(attaque2);
        draw(attaque3);
        draw(attaque4);

        draw(nomAttaque1);
        draw(nomAttaque2);
        draw(nomAttaque3);
        draw(nomAttaque4);

        for(unsigned int k=0;k<team1->getListPersonnage().size();k++)
        {
            draw(PersonnageSwitch[k]);
            draw(iPers[k]);
            draw(nomIcone[k]);

        }
/*
        for(unsigned int n=0;n<team2->getListMob().size();n++)
        {
          //  draw(PersonnageSwitch[k]);
            draw(iMob[n]);
            draw(nomIcone[n]);

        }
*/
        draw(text);
        draw(tour);
        draw(pvLanceur);
        draw(pvEnnemi);

        display();



    }


return EXIT_SUCCESS;

}

