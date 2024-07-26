/*  
	Name: Brannon Alcantar
	Date: 4/27/2019
	Title: RPG Maze Game
*/

#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;

//Parent Class
class Character {
	private:
		string name;
		int health;
	public:
		//Gets & Sets
		void setName(string n) {
			name = n;
		}
		
		string getName() {
			return name;
		}
		
		void setHealth(int h) {
			health = h;
		}
		
		int getHealth() {
			return health;
		}
	
		int operator-(int dmg) {
		 	int HP;
		 	HP = health - dmg;
		 	health = HP;
		}
		
		int operator+(int heal) {
			int HP;
			HP = health + heal;
			health = HP;
		}
};

//Child Class
class Player:public Character {
	public:
		Player() {
			Character::setName("Adventurer");
			Character::setHealth(100);	
		}
};

//Child Class
class Monster:public Character {
	private:
		string item;
		int dmgAmnt;
	public:
		//Arrays of names for randomizing
		string monsterNames[10] = {"Screaming Banshee", "Skeleton", "Dark Reaper", "Rotten Zombie", "Shiny Slime", "Colossal Giant", "Dusk Elf", "Horned Demon", "Wailing Ghost", "Satanic Witch"};
		string itemsArr[10] = {"Sword", "Antidote", "Mace", "Staff", "Emerald", "Amber", "Jade", "Amulate", "Telescope", "Scythe"};
		
		int random(int num) {
			int randNum;
			srand(time(0));
			randNum = (rand() % num) + 1;
			return randNum;
		}
		
		//Default Constructor
		Monster() {
			Character::setName(monsterNames[random(10)]);
			item = itemsArr[random(10)];
			dmgAmnt = random(50);
		}
		 //Non-Default Constructor
		Monster(string name) {
			Character::setName(name);
			item = itemsArr[random(10)];
			dmgAmnt = random(50);
		}

		int getDamage() {
			return dmgAmnt;
		}
		
		string getInvItem() {
			return item;		
		}
		
};

//all the logic for the game.
void game(Player user);

//where all the scenarios come from.
string scenarios(int num);

//random takes in a nuber and randomizes whatever the range inputted is.
int random(int num);

int main() {
	string name;
	//welcome is used to output each character slowly like typing.
	string welcome = "Welcome to Dungeon Crawler!";
	int x=0;
	while ( welcome[x] != '\0') {
	    cout << welcome[x];
	   Sleep(100);
	    x++;
	}
	
	cout<<"\n***************************";
	cout<<"\nPlease enter your name, adventurer: ";
	cin>>name;
	
	Player user;
	user.setName(name);
	
	cout<<"Welcome to the Dungeon "<<user.getName()<<"!"<<endl;
	cout<<"Let us venture forth to the depths below!"<<endl;Sleep(2000);
	
	//game starts
	game(user);
	
	//Checking to see if name is printed 
	//cout<<user.getName();
	
	//Checking to see if monster names print out randomly
	//Monster mon1;
	//cout<<" "<<mon1.getName()<<endl;
}

//ALl logic stored here.
void game(Player user) {
	int sceneNum;
	int sceneCount = 0;
	char userChoice;
	
	//Vector of numbers for keys of the scenarios
	vector <int> scenesEncountered;
	
	try {
		do {
			Sleep(1000);
			sceneNum = random(10);
			//takes in the randomScene Num and goes to the corresponding case.
			switch(sceneNum) {
				case 1:
					cout<<scenarios(1)<<endl;
					sceneCount++;
					break;
				case 2:
					cout<<scenarios(2);
					cin>>userChoice;
					
					 //Data validation using Exception Handling
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						Monster mon2;
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You obtained a(n) "<<mon2.getInvItem()<<"!"<<endl;
							cin.ignore(100, '\n');
						} else {
							Monster mimic("Mimic");
							cout<<"Its a Mimic! ";
							cout<<"You take "<<mimic.getDamage()<<" points of damage!"<<endl;
							user-mimic.getDamage();
							cout<<"Current Health is "<<user.getHealth()<<"!"<<endl;
							cin.ignore(100, '\n');
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					scenesEncountered.push_back(sceneNum);
					break;
				case 3:
					cout<<scenarios(3);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You leaped accross the spikes and you stick the landing! Excellent!"<<endl;
							cin.ignore(100, '\n');
						} else {
							cout<<"You take a great leap yet your efforts were wasted! You fall into the pit!"<<endl;
							user-100;
							cout<<"Current Health is "<<user.getHealth()<<"!"<<endl;
							
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					scenesEncountered.push_back(sceneNum);
					break;
				case 4:
					cout<<scenarios(4);
					user-15;
					cout<<"Current Health is "<<user.getHealth()<<"!"<<endl;
					
					sceneCount++;
					scenesEncountered.push_back(sceneNum);
					break;
				case 5:
					cout<<scenarios(5);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You succesfully removed the ruby on the wall! It must be worth a fortune!"<<endl;
							cin.ignore(100, '\n');
						} else {
							cout<<"You suddenly hear a click once you remove the ruby and a boulder falls ontop of you! You take 100 damage!"<<endl;
							user-100;
							cout<<"Current Health is "<<user.getHealth()<<"!"<<endl;
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					scenesEncountered.push_back(sceneNum);
					break;
				case 6:
					cout<<scenarios(6);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						Monster mon1;
						string item;
						cout<<"You encountered a(n) "<<mon1.getName()<<"!"<<endl;
						
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You take "<<mon1.getDamage()<<" points of damage!"<<endl;
							cin.ignore(100, '\n');
							user-mon1.getDamage();
							cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
						} else {
							cout<<"You killed the "<<mon1.getName()<<" and recieve a(n) "<<mon1.getInvItem()<<endl;
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					
					scenesEncountered.push_back(sceneNum);
					break;
				case 7:
					cout<<scenarios(7);
					user+50;
					cout<<"\nYour current health is "<<user.getHealth()<<"!"<<endl;
					sceneCount++;
					scenesEncountered.push_back(sceneNum);
					break;
				case 8:
					cout<<scenarios(8);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You drink the magical elixir and it heals you for 25HP!"<<endl;
							user+25;
							cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
						} else {
							cout<<"The elixir tastes atrocious and you lose some health for drinking it."<<endl;
							user-15;
							cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					scenesEncountered.push_back(sceneNum);
					break;
				case 9:
					cout<<scenarios(9);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						int outcome = random(2);
						if(outcome == 1) {
							cout<<"You help the lady in distress and you find a priestess hanging over a ledge. You save her and for doing so she says a prayer and heals you for 50HP!"<<endl;
							user+50;
							cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
						} else {
							cout<<"You go to help the lady and find a wicked succubus instead! She inflicts 60 points of damage onto you!"<<endl;
							user-60;
							cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
						}
						sceneCount++;
					} else {
						sceneCount++;
					}
					scenesEncountered.push_back(sceneNum);
					break;
				case 10:
					cout<<scenarios(10);
					cin>>userChoice;
					
					if(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n'  && userChoice != 'N'  ) {
						throw(userChoice);
						break;
					}
					
					if (userChoice == 'y' || userChoice == 'Y') {
						cout<<"In cowardice you sacrifice half of your current health to the demon."<<endl;
						user-(user.getHealth()/2);
						cout<<"Your current health is "<<user.getHealth()<<"!"<<endl;
					} else {
						int outcome = random(2);
						if (outcome = 1) {
							cout<<"You fight the demon instead, and you manage to defeat him unscathed!"<<endl;	
						} else {
							cout<<"You fight the demon and failed to defeat him! You loose 75 points of health!"<<endl;
							user-75;
						}
					}
					
					sceneCount++;
					scenesEncountered.push_back(sceneNum);
					break;
			}

			if(user.getHealth() == 0) {
				cout<<"You died!"<<endl;
				sceneCount = 5;
				break;
			}
			
			 
			if(user.getHealth() < 0) {
				cout<<"You died!"<<endl;
				sceneCount = 5;
				break;
			}
		
		
		} while(sceneCount != 5);
		
		if(user.getHealth() != 0 || user.getHealth() > 0) {
			cout<<"Here are the scene numbers that you have encountered in your journey!"<<endl;
			for (int x = 0; x < sceneCount; ++x) {
				cout<<" "<<scenesEncountered[x];
			}
		}
	}
	 //If c is not y or Y or n or N then it will output this.
	catch(char c) {
		cout<<c<<" is an invalid choice!";
	}
	
}
//end of game function

//This function is used to take a range in and output a random num from that range.
int random(int num) {
	int randomNum;
	srand(time(0));
	randomNum =  rand() % num + 1;
	return randomNum;
}
//end of random function

string scenarios(int num) {
	
	map <int, string> mapOfScenes;
	mapOfScenes.insert(make_pair(1, "Nothing happens in the next room and you continue on your adventure."));
	mapOfScenes.insert(make_pair(2, "You are presented with a chest! Do you open it?"));
	mapOfScenes.insert(make_pair(3, "There is a pit of spikes! Do you attempt to Jump?"));
	mapOfScenes.insert(make_pair(4, "You step in a poison trap! You take 15 damage!"));
	mapOfScenes.insert(make_pair(5, "There is a ruby engraved on the wall! Do you attempt to remove it?"));
	mapOfScenes.insert(make_pair(6, "You encounter a monster! Do you fight it?"));
	mapOfScenes.insert(make_pair(7, "A beautiful angel descends from the ceiling in the room you are in, she heals you for 50HP."));
	mapOfScenes.insert(make_pair(8, "You find a Goblet with a shiny blue liquid inside! Do you drink it?"));
	mapOfScenes.insert(make_pair(9, "You hear lady screaming for help! Do you attend to the damzel in destress?"));
	mapOfScenes.insert(make_pair(10, "A demon appears from below and demands you sacrifice a chunk of your health to him. Do you accept or retaliate?"));
	
	return mapOfScenes.at(num);
}
//end of scenarios function


//Couldnt get the files to work!
/*
void setMonsterItem(Monster monster) {
	string item;
	ifstream file;
	file.open("items.txt");
	
	if(file.fail()) {
		cout<<"File could not be opened!"<<endl;
		exit(1);
	}
	
	int itemChoice = random(20);
	int count = 0;
	while (!file.eof()) {
		count++;
		if(count == itemChoice) {
			file>>item;	
		}
	}

	monster.setInvItem(item);
			
	file.close();
}

*/

