#include "game.h"
#include <ifstream>

Game::Game(char pc, string file = "map.txt"){
  ifstream f {file};
  char c;
  for(int i = 0; i < 25; ++i){
    map.push_back(vector<tile*>);

    for(int j = 0; j < 79; ++j){
      f >> c;
      switch(c){
	case '.' :
          map[i].push_back(new Brick{c, true});
	  break;
	case '+' :
          map[i].push_back(new Brick{c, true});
	case '#' :
	  map[i].push_back(new Brick{c, true});
	case '\\' :
	  map[i].push_back(new Brick{c, true});
	default : //this tile is not walkable
	  map[i].push_back(new Brick{c});
      }
    }
  }
}


Game::~Game(){}


void Game::init(){
//call refreshMap to generate races/items

}



void Game::refreshMap(){
//remove all the races/items on the map


//use generator to generator races/items on the map


//increase floor level

}


void Game::spawnAt(Pair<int, int> p, Tile* t){
  map[p.first][p.second] = t;
}


void Game::movePc(Pair<int, int> p){
  //PC->move(map, p);
}

void Game::moveEnemies(){

}

void Game::usePotion(Pair<int, int> p){
}
