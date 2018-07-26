#include <string>
#include <iostream>
#include "game.h"
using namespace std;

int main (int argc, char* argv[]){
	string filename;

	if(argc == 1){
		filename = argv[1];
	} else if(argc == 2){
		filename = argv[1];
		srand(stoi(argv[2]));
	}

	string welcome = "Hello Welcome to ChamberCrawler3000!";
	string heroes = "		Shade(s)	Drow(d)		Vampire(v)	Goblin(g) 	Troll(t)";
	string hp = "HP: 	125				150				50					110					120";
	string atk = "ATK:     25				 25				25					 15					 25";
	string def = "DEF:	 25				 25				25					 20					 15";
	string choosePc = "Please choose your hero charcter! (s, d, v, g, t, l)";
	cout << welcome << endl;
	cout << choosePc << endl;

	char c;
	cin >> c; //reads in user input to determine which hero the players want to play. 
	Game g {c, filename};
	g.enterFloor();
	cout << g << "player spawned!" << endl;
	bool b = true;

    string s;
	while(cin >> s){
		try{
		if(s == "no" || s == "so" || s == "ea" || s == "we" || 
		s == "ne" || s == "nw" || s == "se" || s == "sw"){
			g.movePC(s);
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
		if(g.won()){
			cout << "Restart game(y or n)?" << endl;
			
			while(1){
				cin >> c;
            if (c == 'y') {
				g.restart();
				break;
			} 
            else if (c == 'n'){
				return 0;
			}
			else {
				cout << "Invalid command, Choose between y or n" << endl;
			}
			}
			cout << g << endl;
			
		}

		if(g.dead()){
			cout << "PC is killed. Do you want to restart(r) or quit(q)?" << endl;
			while(true){
				cin >> c;
				if(c == 'r'){
					g.restart();
					break;
				}
				else if(c == 'q'){
					return 0;
				}
				else{
					cout << "Invalid comman. Choose between r ot q" << endl;
				}
			}
			cout << g << endl;
			
		}
		}
		catch(string err){ 
			cout << g << err << endl;
		}
		catch(const char* err){
			cout << g << err << endl;
		}
	}
}

