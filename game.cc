#include "game.h"
#include "typedef.h"
#include <ifstream>
#include <cstdlib>
#include <ctime>
#include "tile.h"
using namespace std


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

Posn generatorpos() {
  int num, x, y, h, w, s, n, m;
  srand(time(NULL));
  do{
  num = rand() % 5;
  s = rand() % 2;
  switch(num) {
    case 0: 
      x = 3; 
      y = 3;
      h = 4;
      w = 26;
      break;     
    case 1:
      x = 38; 
      y = 10;
      h = 3;
      w = 13;
      break;
    case 2:
      x = 3;
      y = 15;
      h = 7;
      w = 21;
      break;
    case 3:
      if(s) {
        x = 39;
        y = 3;
        h = 4;
        w = 34;
      } else {
        x = 61;
        y = 7;
        h = 6;
        w = 15;
      }
      break;
    case 4:
      if(s) {
        x = 65;
        y = 16;
        h = 3;
        w = 11;
      } else {
        x = 37;
        y = 19;
        h = 3;
        w = 39;
      }      
      break;
  }
    n = rand() % w;
    m = rand() % h;
  } while (!map[x+n][y=m]->isWalkable)
  Posn p{x+n, y+m};
  return p;
}

void Game::generatorStair() {
  Posn &p = generatorpos();
  int px = p.first;
  int py = p.second;
  Tile *newtile = new Tile{'\', true};
  swap(newtile, map[x[y]]);
  delete newtile;
}

void Game::generatorEnemy(){
  srand(time(NULL));
  int num = rand() % 18 + 1;
  Posn &p = generatorpos();
  int px = p.first;
  int py = p.second;
  if (1<=num && num<=4) {
    Tile* newtile = new Human{}; 
  } else if (5<=num && num<=7) {
    Tile* newtile = new Dwarf{};
  } else if (8<=num && num<=12) {
    Tile* newtile = new Halfling{};
  } else if (13<=num && num<=14) {
    Tile* newtile = new Elf{}; 
  } else if (15<=num && num<=16) {
    Tile* newtile = new Orc{};
  } else if (17<=num && num<=18) {
    Tile *newtile = new Merchant{};
  } 
  swap(newtile, map[x[y]]);
  delete newtile;
}

void Game::generatorGold(){
  srand(time(NULL));
  int num = rand() % 8 + 1;
  Posn &p = generatorpos();
  int px = p.first;
  int py = p.second;
  if (1<=num && num<=5) {
    Tile* newtile = new NormalHoard{}; 
  } else if (6<=num && num<=7) {
    Tile* newtile = new SmallHoard{};
  } else if (num==8) {
    int pn = px-1;
    int pm = py-1;
    for (;pn<px+2;++pn) {
      for (;pm<py+2;++pm) {
        if (map[pn][pm]->isWalkable) {break;}
      }
      if (map[pn][pm]->isWalkable) {break;}
    }
    Tile* newtile = new DragonHoard{}; 
    Tile* dragontile = new Dragon{};
    swap(newtile, map[px][py]);
    swap(dragontile, map[pn][pm]);
    delete dragontile;
    delete newtile; 
    return;
  } 
  swap(newtile, map[x[y]]);
  delete newtile;
}

void Game::generatorPotion(){

  srand(time(NULL));
  int num = rand() % 6 + 1;
  Posn &p = generatorpos();
  int px = p.first;
  int py = p.second;
  if (1==num) {
    Tile* newtile = new RH{}; 
  } else if (2==num) {
    Tile* newtile = new BA{};
  } else if (3==num) {
    Tile* newtile = new BD{};
  } else if (4==num) {
    Tile* newtile = new PH{}; 
  } else if (5==num) {
    Tile* newtile = new WA{};
  } else if (6==num) {
    Tile *newtile = new WD{};
  } 
  swap(newtile, map[x[y]]);
  delete newtile;
}







