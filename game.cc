#include "game.h"
#include "typedef.h"
#include <ifstream>
#include <cstdlib>
#include<time.h>
#include <tile.h>
using namespace std;


Game::Game(char pc, string file = "map.txt"){
  ifstream f {file};
  char c;
  for(int i = 0; i < 25; ++i){
    map.push_back(vector<tile*>);

    for(int j = 0; j < 79; ++j){
      f >> c;s
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


void Game::init(){ //initialization should create a random position for pc and calls refreshMap
//call refreshMap to generate races/items

}


//void Game::refreshMap(){
//remove all the races/items on the map


//use generator to generator races/items on the map


//increase floor level

//}


void Game::spawnAt(Posn p, Tile* t){
  map[p.first][p.second] = t;
}


void Game::movePc(Direction d){
  int x= get<0>(PC->getPosn());
  int y= get<1>(PC->getPosn());
  if(d == Direction::no){
     PC->move (map, Posn{x,y+1});
  }else if (d == Direction::so){
     PC->move (map, Posn{x,y-1});
  }else if (d == Direction::ea){
     PC->move (map, Posn{x+1,y});
  }else if (d == Direction::we){
     PC->move (map, Posn{x-1,y});
  }else if (d == Direction::ne){
     PC->move (map, Posn{x+1,y+1});
  }else if (d == Direction::nw){
     PC->move (map, Posn{x-1,y+1});
  }else if (d == Direction::se){
     PC->move (map, Posn{x+1,y-1});
  }else if (d == Direction::sw){
     PC->move (map, Posn{x-1,y-1});
  }
}

void Game::moveEnemies(){
  for (auto i: enemies){
    i->checkSurroundings();
  }
}

void Game::usePotion(Posn p){

}

void Game::generator(){

}