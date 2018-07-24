#include <string>
#include <iostream>
#include "game.h"
using namespace std;

int main (){
	string welcome="Hello Welcome to ChamberCrawler3000!";
	string heroes= "		Shade(s)	Drow(d)		Vampire(v)	Goblin(g) 	Troll(t)";
	    string hp= "HP: 	125				150				50					110					120";
	    string atk="ATK:   25				 25				25					 15					 25";
	    string def="DEF:	 25				 25				25					 20					 15";
	string choosePc= "Please choose your hero charcter! (s , d, v, g, t, l)";
	string mapname= "map.txt";
	cout<<welcome<<endl;
	cout<<choosePC<<endl;
	char c;
	while (cin<<c){//reads in user input to determine which hero the players want to play. 
		if (c=='s'){ //shade
			Game(c, mapname);
		}else if (c== 'd'){//drow
			Game (c, mapname);
		}else if (c=='v'){//vampire
			Game (c, mapname);
		}else if (c=='g'){//goblin
			Game (c, mapname);
		}else if (c=='t'){ //troll
			Game (c, mapname);
		}else if (c== 'l'){ // Slime
			Game (c, mapname);
		}
	}
}

