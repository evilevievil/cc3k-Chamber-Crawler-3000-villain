#include <string>
#include <iostream>
#include "game.h"
using namespace std;

int main (){
	string welcome= "Hello Welcome to ChamberCrawler3000!";
	string choosePc= "Please choose your hero charcter! (s , d, v, g, t)";
	string mapname= "map.txt";
	cout<<welcome<<endl;
	cout<<choosePC<<endl;
	char c;
	while (cin<<c){
		if (c=='s'){
			Game(c, mapname);
		}else if (c== 'd'){
			Game (c, mapname);
		}else if (c=='v'){
			Game (c, mapname);
		}else if (c=='g'){
			Game (c == 'd');
		}else if (c == 'g'){
			Game (c, mapname);
		}else if (c==t){
			Game (c, mapname);
		}
	}
}