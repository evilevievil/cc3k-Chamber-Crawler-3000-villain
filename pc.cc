#include "pc.h"
#include "elf.h"
#include "orcs.h"
#include "potiontype.h"
#include "goldhoard.h"
#include "enemy.h"
#include "brick.h"
#include <string>
using namespace std;


int PC::getGold() {
    return gold;
}

int PC::getScore() {
    return gold;
}

string PC::getName() {
    return name;
}

void PC::setCurTile(Tile* t) {
    curTile = t;
}

// set PC's dead to true if PC's hp falls below 0
void PC::setDead() {
    if (hp <= 0) {
        hp = 0;
        dead = true;
    }
}

void PC::restoreHp(int i) {
    int nhp = hp + i;
    hp = nhp < maxhp ? nhp : maxhp;
}

void PC::addGold(int i) {
    gold += i;
}

void PC::move(Map& map, Posn p) {
    Tile* newTile = map[p.first][p.second];
    // check if new square is walkable
    if (!newTile->isWalkable()) {
        string s = "Invalid Move. Target cannot be walked on!";
        throw s;
    }
    // check if new square is gold
    if (Gold * gold = dynamic_cast<Gold *>(newTile)) {
        gold->affect(*this);
        map[position.first][position.second] = curTile;
        delete newTile;
        curTile = new Brick{ '.', true };
        map[p.first][p.second] = this;
        position = p;
        return;
    }
    // check if new sqaure is stair

    // walk to new square
    map[position.first][position.second] = curTile;
    curTile = newTile;
    map[p.first][p.second] = this;
    position = p;
}

void PC::checkSurroundings(Map& map) {
    // check neighbour squares and add to action the item spotted
    for (int i = position.first - 1; i < position.first + 2; ++i) {
        for (int j = position.second - 1; j < position.second + 2; ++j) {
            action << map[i][j]->beSpotted();
        }
    }
}

// PC that has special end turn actions will override this method
void PC::endTurnAction() {}


// PC is attacked by an enemy
void PC::beAttacked(Enemy& e) {
    int d = damage(e.getAtk(), def);
    hp -= d;
    setDead();
    action << e.getVisual() << " deals " << d << " damage to PC. ";
}

// PC is attacked by an elf
void PC::beAttacked(Elf& e) {
    // Elf attacks twice
    int d = damage(e.getAtk(), def);
    hp -= 2 * d;
    setDead();
    action << e.getVisual() << " deals " << d << " + " << d << " damage to PC. ";
}

// PC is attacked by an Orcs
void PC::beAttacked(Orcs& o) {
    int d = damage(o.getAtk(), def);
    hp -= d;
    setDead();
    action << o.getVisual() << " deals " << d << " damage to PC. ";
}


PC::PC(int maxhp, int hp, int atk, int def, string hero) :
    Race{ '@', maxhp, hp, atk, def }, name{ hero }, gold{ 0 }, atkHistory{ 0 }, defHistory{ 0 } {}


PC::~PC(){
    delete curTile;
}


//overloaded methods for item(gold and potion)

void PC::beAffected(BA &potion) {
    atk = atk + BA_effect;
    atkHistory = atkHistory + BA_effect;
}



void PC::beAffected(BD &potion) {
    def = def + BD_effect;
    defHistory = defHistory + BD_effect;
}



void PC::beAffected(RH &potion) {
    int tmpHP = hp + RH_effect;
    if (tmpHP > maxhp) { hp = maxhp; }
}



void PC::beAffected(WA &potion) {
    atk = atk + WA_effect;
    atkHistory = atkHistory + WA_effect;
}




void PC::beAffected(WD &potion) {
    def = def + WD_effect;
    defHistory = defHistory + WD_effect;
}



void PC::beAffected(PH &potion) {
    int tmpHP = hp + PH_effect;
    if (tmpHP <= 0) { hp = 0; }
}


void PC::beRich(SmallHoard &gold) {
    this->gold = this->gold + Small_effect;
}



void PC::beRich(NormalHoard &gold) {
    this->gold = this->gold + Normal_effect;
}


void PC::beRich(MerchantHoard &gold) {
    this->gold = this->gold + Merchant_effect;
}


void PC::beRich(DragonHoard &gold) {
    this->gold = this->gold + Dragon_effect;
}
