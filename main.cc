#include <string>
#include <iostream>
#include "game.h"
using namespace std;

int main (){
	string welcome = "Hello Welcome to ChamberCrawler3000!";
	string heroes = "		Shade(s)	Drow(d)		Vampire(v)	Goblin(g) 	Troll(t)";
	string hp = "HP: 	125				150				50					110					120";
	string atk = "ATK:     25				 25				25					 15					 25";
	string def = "DEF:	 25				 25				25					 20					 15";
	string choosePc = "Please choose your hero charcter! (s , d, v, g, t, l)";
	cout << welcome << endl;
	cout << choosePc << endl;

	char c;
	cin >> c; //reads in user input to determine which hero the players want to play. 
	Game g {c};
	//g.enterFloor();
	cout << g << "player spawed!" << endl;
	bool b = true;

    string s;
	while(cin >> s){
		try{
		if(s == "no" || s == "so" || s == "ea" || s == "we" || 
		s == "ne" || s == "nw" || s == "se" || s == "sw"){
			g.movePC(s);
			g.oneTurn();
		}
		else if(s == "a"){
			cin >> s;
			g.PCAttack(s);	
			g.oneTurn();
		}
		else if (s == "u"){
			cin >> s;
			g.usePotion(s);
			g.oneTurn();
		}
		else if (s == "f"){
			g.setFreeze(b);
			b = !b;
		}
		else if (s == "r"){
			g.restart();
		}
		else if (s == "q"){
			break;
		}
		else{
			cout << "invalid command" << endl;
		}
		cout << g << endl;
		}
		catch(string s){
			cout << g << s << endl;
		}
	}
}

