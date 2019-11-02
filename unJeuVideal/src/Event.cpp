#include "Event.h"
#include "iostream"

using namespace std;

Event::Event()
{
    //ctor
}

Event::~Event()
{
    //dtor
}

Event::Event(const Event& other)
{
    //copy ctor
}

Event& Event::operator=(const Event& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Event::enemyEncounter(FactoryCharacter &FactoryCharacter, vector<Mob> & mobs)
{
    bool playerTurn = false;
	int choice = 0;

    int coinToss = rand() %2 +1;

    if(coinToss == 1)
    {
        playerTurn = true;
    }
    else{
        playerTurn = false;
    }

    bool escape = false;
    bool playerDefeated = false;
    bool enemiesDefeated = false;

    //Enemies
	int nbrOfEnemies = rand() % 5 + 1;

	for (size_t i = 0; i < nbrOfEnemies; i++)
	{
		mobs.push_back(Mob());
	}

    while (!escape && !playerDefeated && !enemiesDefeated)
    {
        //Menu
        if(playerTurn && !enemiesDefeated)
        {
            cout<<"--- BATTLE MENU ---" <<"\n\n";

            cout<<"0: Escape" <<"\n";
            cout<<"1: Attack" <<"\n";
            cout<<"2: Defend" <<"\n";
            cout<<"3: Use Item" <<"\n";

            cout << "Choice: ";

			cin >> choice;

			while (cin.fail() || choice > 3 || choice < 0)
			{
			    cout << "Faulty input!" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout<<"--- BATTLE MENU ---" <<"\n\n";

                cout<<"0: Escape" <<"\n";
                cout<<"1: Attack" <<"\n";
                cout<<"2: Defend" <<"\n";
                cout<<"3: Use Item" <<"\n";

                cout << "Choice: ";

                cin >> choice;
			}

			//Moves
			switch (choice)
			{
			case 0: //ESCAPE
				escape = true;
				break;

			case 1: //ATTACK

				//Select enemy
				cout << "Select enemy: " << "\n\n";

				for (size_t i = 0; i < mobs.size(); i++)
				{
					cout << i << ": ";
			/*			<< "Level: " << enemies[i].getLevel() << " - " <<
						"HP: " << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - " <<
						"Defence: " << enemies[i].getDefence() << " - " <<
						"Accuracy: " << enemies[i].getAccuracy() << " - " <<
						"Damage: " << enemies[i].getDamageMin() << " - " << enemies[i].getDamageMax() <<
						"\n";*/
				}

			case 2: //DEFEND

				break;

			case 3: //ITEM

				break;

			default:
				break;
			}

			//End turn
			playerTurn = false;
        }
        else if(!playerTurn && !playerDefeated && !escape && !enemiesDefeated)
		{
			cout << "= ENEMY TURN =" << "\n";

			cout << "Continue..." << "\n\n";

			//Enemy attack
			for (size_t i = 0; i < mobs.size(); i++)
			{
				cout << "Continue..." << "\n\n";

				cout << "Enemy: " << i << "\n\n";

			}
        }
  /*      if(!FactoryCharacter.isAlive())
        {
            playerDefeated=true;
        }*/
        else if(mobs.size()<=0)
        {
            enemiesDefeated=true;
        }
    }
}
