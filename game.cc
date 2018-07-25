#include "game.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "slime.h"
#include "human.h"
#include "elf.h"
#include "orcs.h"
#include "dwarf.h"
#include "dragon.h"
#include "halfling.h"
#include "merchant.h"
#include "goldhoard.h"
#include "potiontype.h"
#include "brick.h"
 
using namespace std;


Game::Game(char pc, string file){
  ifstream f {file};
  string line;
  for(int i = 0; i < 25; ++i){
    getline(f, line);
    vector<Tile*> row;
    map.push_back(row);

    for(char c : line){
      switch(c){
	    case '.' :
          map[i].push_back(new Brick{c, true});
	        break;
	    case '+' :
          map[i].push_back(new Brick{c, true});
          break;
	    case '#' :
          map[i].push_back(new Brick{c, true});
          break;
      case '\\' :
          map[i].push_back(new Brick{c, true});
          break;
      default : //this tile is not walkable
          map[i].push_back(new Brick{c});
          break;
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


void Game::restart(){ 
  cleanMap();
  delete PC;
  floornum = 0;
  ++floornum;
  allocatorPC();
  generatorStair();
  for (int i=0; i<10; ++i) {generatorPotion();}
  for (int i=0; i<10; ++i) {generatorGold();}
  for (int i=0; i<10; ++i) {generatorEnemy();}
}


void Game::enterFloor(){
  if(floornum != 0){
    cleanMap();
  }
  ++floornum;
  allocatorPC();
  generatorStair();
  for (int i=0; i<10; ++i) {generatorPotion();}
  for (int i=0; i<10; ++i) {generatorGold();}
  for (int i=0; i<10; ++i) {generatorEnemy();}
}


void Game::cleanMap(){
  for(auto i : map) {
    for(auto j : i) {
      char v = j->getVisual();
      if(v != '.' && v != '|' && v != '-' && v != '+' && v != '#' && v != ' '){
        if(v != '@') delete j; // keep PC alive, delete all other stuff

        j = new Brick{'.', true};
      }
    } 
  }
  enemies.clear();
}


void Game::spawnAt(Posn p, Tile* t){
  map[p.first][p.second] = t;
}

Posn Game::dirpos(std::string d, Posn p) {
  int x = p.first;
  int y = p.second;
  if(d == "no"){
    return Posn{x,y+1};
  }else if (d == "so"){
    return Posn{x,y-1};
  }else if (d == "ea"){
     return Posn{x+1,y};
  }else if (d == "we"){
    return Posn{x-1,y};
  }else if (d == "ne"){
    return Posn{x+1,y+1};
  }else if (d == "nw"){
    return Posn{x-1,y+1};
  }else if (d == "se"){
    return Posn{x+1,y-1};
  }else if (d == "sw"){
    return Posn{x-1,y-1};
  } else {throw "Invalid direction";}
}



void Game::movePC(std::string d){
  PC->move (map, dirpos(d, PC->getPosn()));
  PC->action << "PC moves " << d << ". ";
}

void Game::moveEnemies(){
  for (auto i: enemies){
    i->checkSurroundings(map);
  }
}

void Game::PCAttack(string d){
  Posn p = dirpos(d, PC->getPosn());
  PC->attack(map[p.first][p.second]);
}

void Game::usePotion(std::string d){
  Posn p = dirpos(d, PC->getPosn());
  Tile * potiontile = map[p.first][p.second];
  if (Potion *potion = dynamic_cast<Potion *>(potiontile)) {
    potion->affect(*PC); //update action string after methods are completed
  } 
  else {
    throw "Invalid use potion";
  }
}

Posn Game::generatorpos() {
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
  } while (map[y+m][x+n]->getVisual() != '.');
  Posn p{x+n, y+m};
  return p;
}

void Game::allocatorPC() {
  Posn p = generatorpos();
  int px = p.first;
  int py = p.second;
  PC->setPosn(p);
  PC->setCurTile(map[py][px]);
  map[py][px] = PC;
}

void Game::generatorStair() {
  Posn p = generatorpos();
  int px = p.first;
  int py = p.second;
  Tile *newtile = new Brick{'\\', true};
  swap(newtile, map[py][px]);
  delete newtile;
}

void Game::generatorEnemy(){
  int num = rand() % 18 + 1;
  Posn p = generatorpos();
  Tile* newtile;
  int px = p.first;
  int py = p.second;
  if (1<=num && num<=4) {
    newtile = new Human{}; 
  } else if (5<=num && num<=7) {
    newtile = new Dwarf{};
  } else if (8<=num && num<=12) {
    newtile = new Halfling{};
  } else if (13<=num && num<=14) {
    newtile = new Elf{}; 
  } else if (15<=num && num<=16) {
    newtile = new Orcs{};
  } else if (17<=num && num<=18) {
    newtile = new Merchant{};
  } 
  dynamic_cast<Enemy *>(newtile)->setPosn(p);
  swap(newtile, map[py][px]);
  delete newtile;
  enemies.push_back(dynamic_cast<Enemy *>(map[py][px])); //someone check my syntax
}

void Game::generatorGold(){
  int num = rand() % 8 + 1;
  Posn p = generatorpos();
  Tile* newtile;
  int px = p.first;
  int py = p.second;

  if (1<=num && num<=5) {
    newtile = new NormalHoard{}; 
  } else if (6<=num && num<=7) {
    newtile = new SmallHoard{};
  } else if (num==8) {
    int pn = px-1;
    int pm = py-1;
    for (;pn<px+2;++pn) {
      for (;pm<py+2;++pm) {
        if (map[pm][pn]->getVisual() == '.') {break;}
      }
      if (map[pm][pn]->getVisual() == '.') {break;}
    }
    newtile = new DragonHoard{}; 
    Tile* dragontile = new Dragon{newtile};
    swap(dragontile, map[pm][pn]);
    delete dragontile;
  } 

  swap(newtile, map[py][px]);
  delete newtile;
}

void Game::generatorPotion(){

  int num = rand() % 6 + 1;
  Posn p = generatorpos();
  Tile* newtile;
  int px = p.first;
  int py = p.second;
  if (1==num) {
    newtile = new RH{}; 
  } else if (2==num) {
    newtile = new BA{};
  } else if (3==num) {
    newtile = new BD{};
  } else if (4==num) {
    newtile = new PH{}; 
  } else if (5==num) {
    newtile = new WA{};
  } else if (6==num) {
    newtile = new WD{};
  } 
  swap(newtile, map[py][px]);
  delete newtile;
}


void Game::setFreeze(bool b){
  freeze = b;
}

void Game::oneTurn(){
  if(! freeze){
    for(int i = 0; i < enemies.size(); ++i){
      enemies[i]->checkSurroundings(map);
    }
  }
  PC->endTurnAction();
}

ostream& operator<<(ostream& out, Game &g){
   for(auto i : g.map){
     for(auto j : i){
       cout << j->getVisual();
     }
     cout << endl;
   }

  string hero= g.PC->getName();
  int gold = g.PC->getGold();
  int hp = g.PC->getHp();
  int atk = g.PC->getAtk();
  int def = g.PC->getDef();

  cout << "Race: " << hero << "  Gold: " << gold << "   Floor " << g.floornum << endl;
  cout << "HP: " << hp << endl;
  cout << "ATK: " << atk << endl;
  cout << "DEF: " << def << endl;
  cout << "Action :" << g.PC->action.str();
  g.PC->action.str("");
  g.PC->action.clear();
  return out;
}


