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
    int nbRound=1;
    int randAtt;
    int randEnnemy;
    bool retaliate = false; //riposter

    Character J1;   //Les 2 persos en combat
    Character J2;

    Font police;

    Text nameUser, nameEnnemy, nameAttack1,nameAttack2,nameAttack3,nameAttack4,hpUser,hpEnnemy, mana1, mana2, mana3, mana4;


    Texture fond, p1, p2;  //texture fond + perso 1...
    Sprite user;
    Sprite ennemy;

    //element de l'equipe en bas à droite
    Sprite iPers[2];
    RectangleShape CharacterSwitch[2];

    Texture textIcone[2];

    Image icone;

    RectangleShape wallpaper; //fond du jeu

    //barre de vie du Joueur1 et Joueur2
    RectangleShape hpUserBar(Vector2f(200,20));
    RectangleShape hpEnnemyBar(Vector2f(200,20));

    //bords blanc des barres de vies
    RectangleShape hpUserBar_side(Vector2f(204,24));
    RectangleShape hpEnnemyBar_side(Vector2f(204,24));

    //creations des rectangles pour les attaques
    RectangleShape attack1(Vector2f(150,50));
    RectangleShape attack2(Vector2f(150,50));
    RectangleShape attack3(Vector2f(150,50));
    RectangleShape attack4(Vector2f(150,50));

    //creation du rectangle blanc où les actions s'écrivent
	RectangleShape showText(Vector2f(800,200));

	Text nomIcone[6];

    Text text;

    Text round;


    string script="";


    Event event;

    srand(time(0));

    create(VideoMode(1200,700),"Ultimate Fantasy",sf::Style::Close); //creation de la fenetre

    //donne une couleur à rectangle contenant l'attaque + celui du milieu
    attack1.setFillColor(Color::Blue);
    attack2.setFillColor(Color::Blue);
    attack3.setFillColor(Color::Blue);
    attack4.setFillColor(Color::Blue);
    showText.setFillColor(Color::White);

    //position de ces elements graphiques
    attack1.setPosition(0,getSize().y-50);
    attack2.setPosition(200,getSize().y-50);
    attack3.setPosition(400,getSize().y-50);
    attack4.setPosition(600,getSize().y-50);

    showText.setPosition(0,getSize().y-280);

    //positions des élements pour l'équipe
    CharacterSwitch[0].setPosition(900,getSize().y-170);
    CharacterSwitch[1].setPosition(1100,getSize().y-170);

    for(int i=0; i<2;i++)
    {
        nomIcone[i].setPosition(CharacterSwitch[i].getPosition().x+50,CharacterSwitch[i].getPosition().y);
    }

    text.setFont(police);

	round.setFont(police);
	round.setPosition(0,0);

	text.setColor(sf::Color::Black);

	text.setPosition(5,getSize().y-260);
	text.setCharacterSize(15);

	J1=team1->getListCharacter()[0];
	J2=team2->getListCharacter()[0];

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

    wallpaper.setSize(Vector2f(getSize().x,getSize().y));
    wallpaper.setTexture(&fond);
    wallpaper.setPosition(0,0);


    while(this->isOpen()){
        randAtt=rand()%4; //permet à l'ia de choisir entre les 4 attaques prédefini

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

                       if(!J1.isKO()){
                        /***********************************Attaques ***************************/
                            if (attack1.getGlobalBounds().contains(mouseX,mouseY)){        //si on clique sur les boutons d'attaque
                                    if(J1.getAttack()[0].getMana()>0){ //verification que le mana soit >0
                                       if(J1.getSpeed()>=J2.getSpeed()) //compare la vitesse des 2 perso pour savoir qui attaque en premier
                                        {
                                            //le perso 1 lance l'attaque
                                                script=J1.sendAttack(J1.getAttack()[0],&J2);
                                            //si le joueur 2 n'est pas mort, il attaque aussi
                                                if(!J2.isKO())
                                                {
                                                    script+=J2.sendAttack(J2.getAttack()[randAtt],&J1);
                                                }

                                        }
                                        else{
                                            script+=J2.sendAttack(J2.getAttack()[randAtt],&J1);

                                            if(!J1.isKO())
                                            {
                                                script=J1.sendAttack(J1.getAttack()[0],&J2);
                                            }
                                        }
                                        //décrémente le mana de l'attaque utiliser
                                        J1.getAttack()[0].setMana(J1.getAttack()[0].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbRound ++;

                                    }
                                    else{

                                        J1.getAttack()[0].setMana(0);
                                        script="Plus de Mana";
                                    }
                       }

                       if(attack2.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[1].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.sendAttack(J1.getAttack()[1],&J2)+"\n";

                                    if(!J2.isKO())
                                    {
                                        script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";

                                    }

                                }else{
                                    script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";

                                    if(!J1.isKO())
                                    {
                                        script=J1.sendAttack(J1.getAttack()[1],&J2)+"\n";
                                    }
                                }
                                        J1.getAttack()[1].setMana(J1.getAttack()[1].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbRound ++;

                                    }
                                    else{

                                        J1.getAttack()[1].setMana(0);
                                        script="Plus de Mana";
                                    }
                           }

                       if(attack3.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[2].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.sendAttack(J1.getAttack()[2],&J2)+"\n";

                                    if(!J2.isKO())
                                    {
                                        script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";
                                    }

                                }else{
                                    script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";

                                    if(!J1.isKO())
                                    {
                                        script=J1.sendAttack(J1.getAttack()[2],&J2)+"\n";
                                    }
                                }
                                        J1.getAttack()[2].setMana(J1.getAttack()[2].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbRound ++;

                                    }
                                    else{

                                        J1.getAttack()[2].setMana(0);
                                        script="Plus de Mana";
                                    }
                           }

                       if(attack4.getGlobalBounds().contains(mouseX,mouseY))
                       {
                           if(J1.getAttack()[3].getMana() >0)
                           {
                               if(J1.getSpeed()>=J2.getSpeed())
                                {
                                    script=J1.sendAttack(J1.getAttack()[3],&J2)+"\n";

                                    if(!J2.isKO())
                                    {
                                        script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";
                                    }

                                }else{
                                    script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";

                                    if(!J1.isKO())
                                    {
                                        script=J1.sendAttack(J1.getAttack()[3],&J2)+"\n";
                                    }
                                }
                                        J1.getAttack()[3].setMana(J1.getAttack()[3].getMana()-1);
                                        J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);

                                        nbRound ++;

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

                    for(unsigned int i=0;i<team1->getListCharacter().size();i++)
                    {
                        if(CharacterSwitch[i].getGlobalBounds().contains(mouseX, mouseY))
                        {
                            if(!J1.isKO())
                            {
                                retaliate = true;
                                //si on echange de personnage, le joueur 2 riposte et on perds donc un tour
                            }

                            if(team1->getListCharacter()[i].getName()==J1.getName())
                            {
                                script = J1.getName()+" est deja en combat ! \n";
                                //empeche de renvoyer le personnage deja present en combat
                            }
                            else{

                                script=J1.getName()+" est retire par le joueur !\n";
                                script+="Le joueur envoie "+team1->getListCharacter()[i].getName()+" !\n";

                                for(unsigned int j=0;j<team1->getListCharacter().size();j++){
                                        if (team1->getListCharacter()[j].getName()==J1.getName()){      //on cherche l'ancien perso dans la liste
                                            team1->removeCharacter(j);                                 //on le supprime
                                            team1->insertCharacter(J1,j);                              //on met à jour le personnage avant le switch
                                        }
                                    }

                                J1=team1->getListCharacter()[i];

                                if(!p1.loadFromFile(J1.getPath(true)))
                                {
                                    return -1;
                                }

                                user.setScale(1,1);
                                hpUserBar.setScale(1,1);
                                hpUserBar_side.setScale(1,1);
                                hpUser.setScale(1,1);
                                nameUser.setScale(1,1);



                                if (retaliate)
                                {               //si on switche sans etre KO, l'ennemi attaque quand meme
                                    retaliate=false;
                                    script+=J2.sendAttack(J2.getAttack()[randAtt],&J1)+"\n";
                                    J2.getAttack()[randAtt].setMana(J2.getAttack()[randAtt].getMana()-1);
                                    nbRound++;
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

    if(J2.isKO())
    {
        if(team2->isEmpty())
        {
            ennemy.setScale(0,0);
            hpEnnemyBar.setScale(0,0);
            hpEnnemyBar_side.setScale(0,0);
            hpEnnemy.setScale(0,0);
            nameEnnemy.setScale(0,0);

            script="\n L'ennemi a perdu !\n";

            //fin du jeu si l'ennemi perds : ferme la fenetre
            sf::sleep(sf::milliseconds(2000));
            return -1;



        }else
        {
            for(unsigned int i=0;i<team2->getListCharacter().size();i++)
            {
                if(team2->getListCharacter()[i].getName()==J2.getName())
                {
                    team2->removeCharacter(i); //suppresion du l'ennemi dans la liste
                }
            }

            for(unsigned int i=0; i<team2->getListCharacter().size(); i++)
            {
                randEnnemy=rand()%(team2->getListCharacter().size());
                {
                    J2=team2->getListCharacter()[randEnnemy]; //ajoute un perso aleatoire de son equipe sur le terrain, ici le dernier car equipe de 2
                }
            }

            script+="\n L'ennemi "+J2.getName()+" apparait sur le terrain !\n";

        }

    }

    /**************************************Gestion des KO pour joueur ****************************************/

    if(J1.isKO())
    {

        user.setScale(0,0);
        hpUserBar.setScale(0,0);
        hpUserBar_side.setScale(0,0);
        hpUser.setScale(0,0);
        nameUser.setScale(0,0);


        if(team1->isEmpty())
        {
            script="\n Le joueur a perdu !";

        //fin du jeu si on gagne: ferme la fenetre
            sf::sleep(sf::milliseconds(1000));
            return -1;

        }else
        {
            for(unsigned int i=0;i<team1->getListCharacter().size();i++)
            {
                if(team1->getListCharacter()[i].getName()==J1.getName())
                {
                    team1->removeCharacter(i); //suppresion du personnage dans la liste
                }
            }

        }
    }

    /**************************************Chargement et position du sprite ****************************************/

    if (!p1.loadFromFile(J1.getPath(false),IntRect(150,200,0,0))){ // Si le chargement du fichier a �chou�
                  return -1; // On ferme le programme
    }else{
        p1.setSmooth(true);
        user.setTexture(p1);
        user.setTextureRect(IntRect(-100,0,200, 150));
        user.setPosition(0, getSize().y-450);
    }


     if (!p2.loadFromFile(J2.getPath(true),IntRect(150,200,0,0)))
    {
        return -1;
    }else
    {
        p2.setSmooth(true);
        ennemy.setTexture(p2);
        ennemy.setTextureRect(IntRect(0,0,200,150));
        ennemy.setPosition(getSize().x-300,getSize().y-450);
    }


    /**************************************Icone et bouton switch ****************************************/

    for(unsigned int i=0;i<team1->getListCharacter().size();i++)
    {
        if(!textIcone[i].loadFromFile(PATH_IMAGE+ICON+team1->getListCharacter()[i].getName()+EXTENSION_IMAGE))
        {
            cout <<"Erreur lors du chargement de getlistperso"<<endl;
            return -1;
        }else{
            textIcone[i].setSmooth(true);
            iPers[i].setTexture(textIcone[i]);
            iPers[i].setPosition(CharacterSwitch[i].getPosition().x+5, CharacterSwitch[i].getPosition().y+5);
        }

        CharacterSwitch[i].setSize(Vector2f(140, 150));
        nomIcone[i].setFont(police);
        nomIcone[i].setString(team1->getListCharacter()[i].getName());
        nomIcone[i].setColor(Color::Black);
        nomIcone[i].setScale(0.5, 0.5);

    }


    /**************************************Position et tailles des boutons/textes ****************************************/

        hpUserBar.setPosition(user.getPosition().x+user.getTextureRect().width,(user.getPosition().y+user.getTextureRect().height/4)-100);
        hpEnnemyBar.setPosition(ennemy.getPosition().x-ennemy.getTextureRect().width-150,(ennemy.getPosition().y+ennemy.getTextureRect().height/4)-100);

        hpUserBar_side.setPosition(hpUserBar.getPosition().x-2,hpUserBar.getPosition().y-2);
        hpEnnemyBar_side.setPosition(hpEnnemyBar.getPosition().x-2,hpEnnemyBar.getPosition().y-2);

        hpUserBar_side.setOutlineColor(Color::Black);
        hpEnnemyBar_side.setOutlineColor(Color::Black);


        nameUser.setString(J1.getName());
        nameUser.setFont(police);
        nameUser.setColor(Color::Red);
        nameUser.setPosition(user.getPosition().x+user.getTextureRect().width,user.getPosition().y-100);

        nameEnnemy.setString(J2.getName());
        nameEnnemy.setFont(police);
        nameEnnemy.setColor(Color::Blue);
        nameEnnemy.setPosition(hpEnnemyBar.getPosition().x,hpEnnemyBar.getPosition().y-42);

        nameAttack1.setString(J1.getAttack()[0].getName());
        nameAttack1.setFont(police);
        nameAttack1.setPosition(attack1.getPosition());
        nameAttack1.setScale(0.75, 0.75);
        mana1.setFont(police);
        mana1.setString(" Mana: "+Character::toString(J1.getAttack()[0].getMana())+"/"+Character::toString(J1.getAttack()[0].getManaFix()));
        mana1.setPosition(nameAttack1.getPosition().x, nameAttack1.getPosition().y+30);
        mana1.setScale(0.5, 0.5);

        nameAttack2.setString(J1.getAttack()[1].getName());
        nameAttack2.setFont(police);
        nameAttack2.setPosition(attack2.getPosition());
        nameAttack2.setScale(0.75, 0.75);
        mana2.setFont(police);
        mana2.setString(" Mana: "+Character::toString(J1.getAttack()[1].getMana())+"/"+Character::toString(J1.getAttack()[1].getManaFix()));
        mana2.setPosition(nameAttack2.getPosition().x, nameAttack2.getPosition().y+30);
        mana2.setScale(0.5, 0.5);

        nameAttack3.setString(J1.getAttack()[2].getName());
        nameAttack3.setFont(police);
        nameAttack3.setPosition(attack3.getPosition());
        nameAttack3.setScale(0.75, 0.75);
        mana3.setFont(police);
        mana3.setString(" Mana: "+Character::toString(J1.getAttack()[2].getMana())+"/"+Character::toString(J1.getAttack()[2].getManaFix()));
        mana3.setPosition(nameAttack3.getPosition().x, nameAttack3.getPosition().y+30);
        mana3.setScale(0.5, 0.5);

        nameAttack4.setString((J1.getAttack()[3]).getName());
        nameAttack4.setFont(police);
        nameAttack4.setPosition(attack4.getPosition());
        nameAttack4.setScale(0.75, 0.75);
        mana4.setFont(police);
        mana4.setString(" Mana: "+Character::toString(J1.getAttack()[3].getMana())+"/"+Character::toString(J1.getAttack()[3].getManaFix()));
        mana4.setPosition(nameAttack4.getPosition().x, nameAttack4.getPosition().y+30);
        mana4.setScale(0.5, 0.5);

        //point de vie en fonction des degats

        if((100*J1.getLifePoint()/J1.getLifePointMax()) >=50)
        {
            hpUserBar.setFillColor(Color::Green);


        }else if((100*J1.getLifePoint()/J1.getLifePointMax()) >=20){
            hpUserBar.setFillColor(Color::Yellow);

        }else{
            hpUserBar.setFillColor(Color::Red);
        }


        if((100*J2.getLifePoint()/J2.getLifePointMax()) >=50)
        {
            hpEnnemyBar.setFillColor(Color::Green);

        }else if((100*J2.getLifePoint()/J2.getLifePointMax()) >=20){
            hpEnnemyBar.setFillColor(Color::Yellow);

        }else{
            hpEnnemyBar.setFillColor(Color::Red);
        }

        text.setString(script);
        round.setString("Tour : "+Character::toString(nbRound)+"\nPersonnages restants: "+Character::toString((int)team2->getListCharacter().size()));

        hpUserBar.setSize(Vector2f((J1.getLifePoint()*200)/J1.getLifePointMax(),20));
        hpEnnemyBar.setSize(Vector2f((J2.getLifePoint()*200)/J2.getLifePointMax(),20));

        hpUser.setFont(police);
        hpUser.setString(Character::toString(100*J1.getLifePoint()/J1.getLifePointMax())+"%");
        hpUser.setPosition(hpUserBar.getPosition().x+hpUserBar.getSize().x-hpUser.getGlobalBounds().width,hpUserBar.getPosition().y);
        hpUser.setCharacterSize(18);
        hpUser.setColor(Color::Black);


        hpEnnemy.setFont(police);
        hpEnnemy.setString(Character::toString(100*J2.getLifePoint()/J2.getLifePointMax())+"%");
        hpEnnemy.setPosition(hpEnnemyBar.getPosition().x+hpEnnemyBar.getSize().x-hpEnnemy.getGlobalBounds().width,hpEnnemyBar.getPosition().y);
        hpEnnemy.setCharacterSize(18);
        hpEnnemy.setColor(Color::Black);

        /**********************Affichages*******************/

        clear(Color::White);

        draw(wallpaper);

        draw(user);
        draw(ennemy);

        draw(showText);

        draw(hpUserBar_side);
        draw(hpEnnemyBar_side);

        draw(hpUserBar);
        draw(hpEnnemyBar);

        draw(attack1);
        draw(attack2);
        draw(attack3);
        draw(attack4);

        draw(nameAttack1);
        draw(nameAttack2);
        draw(nameAttack3);
        draw(nameAttack4);

        draw(mana1);
        draw(mana2);
        draw(mana3);
        draw(mana4);


        for(unsigned int k=0;k<team1->getListCharacter().size();k++)
        {
            draw(CharacterSwitch[k]);
            draw(iPers[k]);
            draw(nomIcone[k]);

        }

        draw(text);
        draw(round);
        draw(hpUser);
        draw(hpEnnemy);

        display();



    }


return EXIT_SUCCESS;

}

