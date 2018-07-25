#include "game.h"
#include "typedef.h"
#include <ifstream>
#include <cstdlib>
#include <ctime>
#include "tile.h"
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
  
  switch(pc) {
  case 's' : PC = new Shade();
             break;
  case 'd' : PC = new Drow();
             break;
  case 'v' : PC = new Vampire();
             break;
  case 'g' : PC = new Goblin();
             break;
  case 't' : PC = new Troll();
             break;
  default  : throw "Invalid PC type";
             break; 
  }
}


Game::~Game(){
  
  for (auto i : map) {
    for (auto j : i) {
      delete j;
    }
  }

}


void Game::init(){ //initialization should create a random position for pc and calls refreshMap
//call refreshMap to generate races/items
  generatorStair();
  generatorPotion();
  generatorGold();
  generatorEnemy();
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

  Tile * potiontile = map[p.first][p.second]; 
  if (Potion *potion = dymamic_cast<Potion *>(potiontile)) {
    potion->affect(*PC); //update action string after methods are completed
  } else {throw "Invalid use potion";}
}


void Game::generatorStair() {}
void Game::generatorEnemy(){}

void Game::generatorGold(){}

void Game::generatorPotion(){}


void Game::printStats(){
  string hero= pc->getName();
  int gold= pc->getGold();
  int hp= pc->getHp();
  int atk=pc->getAtk();
  int def=pc->getDef();

  cout<<"Race: "<<hero<<"  Gold: "<< gold<< "                                         Floor "<< floornum<<endl;
  cout<<"HP: "<< hp<<endl;
  cout<<"ATK: "<<atk<<endl;
  cout<<"DEF: "<<def<<endl;
  cout<<"Action :"<<pc->action.str()<<endl;
}




