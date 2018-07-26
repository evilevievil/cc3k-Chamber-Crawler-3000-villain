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


Game::Game(char pc, string file) {
    ifstream f{ file };
    string line;
    for (int i = 0; i < 25; ++i) {
        getline(f, line);
        vector<Tile*> row;
        map.push_back(row);

        for (char c : line) {
            switch (c) {
            case '.':
                map[i].push_back(new Brick{ c, true });
                break;
            case '+':
                map[i].push_back(new Brick{ c, true });
                break;
            case '#':
                map[i].push_back(new Brick{ c, true });
                break;
            case '\\':
                map[i].push_back(new Brick{ c, true });
                break;
            default: //this tile is not walkable
                map[i].push_back(new Brick{ c });
                break;
            }
        }
    }

    switch (pc) {
    case 's': PC = new Shade();
        break;
    case 'd': PC = new Drow();
        break;
    case 'v': PC = new Vampire();
        break;
    case 'g': PC = new Goblin();
        break;
    case 't': PC = new Troll();
        break;
    default: throw "Invalid PC type";
        break;
    }
}


Game::~Game() {

    for (auto i : map) {
        for (auto j : i) {
            delete j;
        }
    }

}

bool Game::won() {
    return win;
}


bool Game::dead() {
    return PC->getDead();
}


void Game::restart() {
    cleanMap();
    delete PC;
    floornum = 1;

    cout << "Please choose your hero charcter! (s , d, v, g, t, l)" << endl;
    char pc;
    cin >> pc;
    switch (pc) {
    case 's': PC = new Shade();
        break;
    case 'd': PC = new Drow();
        break;
    case 'v': PC = new Vampire();
        break;
    case 'g': PC = new Goblin();
        break;
    case 't': PC = new Troll();
        break;
    default: cout << "Invalid Character. Please choose again." << endl;
        break;
    }
    PC->action << "Player spawned!";

    Merchant::resetHostile();
    BA::setKnowsType(false);
    BD::setKnowsType(false);
    PH::setKnowsType(false);
    WA::setKnowsType(false);
    WD::setKnowsType(false);
    RH::setKnowsType(false);

    generatorStair();
    for (int i = 0; i < 10; ++i) { generatorPotion(); }
    for (int i = 0; i < 10; ++i) { generatorGold(); }
    for (int i = 0; i < 20; ++i) { generatorEnemy(); }
}


void Game::enterFloor() {
    if (floornum != 0) {
        cleanMap();
    }
    ++floornum;
    generatorStair();
    for (int i = 0; i < 10; ++i) { generatorPotion(); }
    for (int i = 0; i < 10; ++i) { generatorGold(); }
    for (int i = 0; i < 20; ++i) { generatorEnemy(); }
}


void Game::cleanMap() {
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 79; ++j) {
            char v = map[i][j]->getVisual();
            if (v != '.' && v != '|' && v != '-' && v != '+' && v != '#' && v != ' ') {
                if (v != '@') { delete map[i][j]; } // keep PC alive, delete all other stuff

                map[i][j] = new Brick{ '.', true };
            }
        }
    }

    enemies.clear();
}


Posn Game::dirpos(std::string d, Posn p) {
    int row = p.first;
    int col = p.second;
    if (d == "no") {
        return Posn{ row - 1, col };
    }
    else if (d == "so") {
        return Posn{ row + 1, col };
    }
    else if (d == "ea") {
        return Posn{ row, col + 1 };
    }
    else if (d == "we") {
        return Posn{ row, col - 1 };
    }
    else if (d == "ne") {
        return Posn{ row - 1, col + 1 };
    }
    else if (d == "nw") {
        return Posn{ row - 1, col - 1 };
    }
    else if (d == "se") {
        return Posn{ row + 1, col + 1 };
    }
    else if (d == "sw") {
        return Posn{ row + 1, col - 1 };
    }
    else { throw "Invalid direction"; }
}



void Game::movePC(std::string d) {
    Posn p = PC->getPosn();
    Posn np = dirpos(d, p);
    if (map[np.first][np.second]->getVisual() == '\\') {
        if (floornum == 4) {
            PC->action << "You completed all 4 levels! Your score is: " << PC->getScore();
            win = true;
        }
        else {
            enterFloor();
            PC->action << "PC enters new level. ";
        }
    }
    else {
        PC->move(map, np);
        PC->action << "PC moves " << d << ". ";
        oneTurn();
    }
}

void Game::moveEnemies() {
    for (auto i : enemies) {
        i->checkSurroundings(map);
    }
}

void Game::PCAttack(string d) {
    Posn p = dirpos(d, PC->getPosn());
    PC->attack(map[p.first][p.second]);
}

void Game::usePotion(std::string d) {
    Posn p = dirpos(d, PC->getPosn());
    Tile * potiontile = map[p.first][p.second];
    if (Potion *potion = dynamic_cast<Potion *>(potiontile)) {
        potion->affect(*PC); //update action string after methods are completed
    }
    else {
        throw "Invalid use potion";
    }
    delete map[p.first][p.second];
    map[p.first][p.second] = new Brick{ '.', true };
}

Posn Game::generatorpos(int num) {
    int  x, y, h, w, s;
    do {
        s = rand() % 2;
        switch (num) {
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
            if (s) {
                x = 39;
                y = 3;
                h = 4;
                w = 34;
            }
            else {
                x = 61;
                y = 7;
                h = 6;
                w = 15;
            }
            break;
        case 4:
            if (s) {
                x = 65;
                y = 16;
                h = 3;
                w = 11;
            }
            else {
                x = 37;
                y = 19;
                h = 3;
                w = 39;
            }
            break;
        }
        x += rand() % w;
        y += rand() % h;
    } while (map[y][x]->getVisual() != '.');
    Posn p{ y, x };
    return p;
}

void Game::allocatorPC(int num) {
    Posn p = generatorpos(num);
    int py = p.first;
    int px = p.second;
    PC->setPosn(p);
    PC->setCurTile(map[py][px]);
    map[py][px] = PC;
}

void Game::generatorStair() {
    int num = rand();
    allocatorPC(num % 5);
    ++num;
    Posn p = generatorpos(num % 5);
    int py = p.first;
    int px = p.second;
    Tile *newtile = new Brick{ '\\', true };
    swap(newtile, map[py][px]);
    delete newtile;
}

void Game::generatorEnemy() {
    int num = rand() % 18 + 1;
    Posn p = generatorpos(rand() % 5);
    Tile* newtile;
    int py = p.first;
    int px = p.second;
    if (1 <= num && num <= 4) {
        newtile = new Human{};
    }
    else if (5 <= num && num <= 7) {
        newtile = new Dwarf{};
    }
    else if (8 <= num && num <= 12) {
        newtile = new Halfling{};
    }
    else if (13 <= num && num <= 14) {
        newtile = new Elf{};
    }
    else if (15 <= num && num <= 16) {
        newtile = new Orcs{};
    }
    else {
        newtile = new Merchant{};
    }
    Enemy* e = dynamic_cast<Enemy *>(newtile);
    e->setPosn(p);
    swap(newtile, map[py][px]);
    delete newtile;
    enemies.push_back(e); //someone check my syntax
}

void Game::generatorGold() {
    int num = rand() % 8 + 1;
    Posn p = generatorpos(rand() % 5);
    Tile* newtile;
    int py = p.first;
    int px = p.second;

    if (1 <= num && num <= 5) {
        newtile = new NormalHoard{};
    }
    else if (6 <= num && num <= 7) {
        newtile = new SmallHoard{};
    }
    else if (num == 8) {
        int pn = px - 1;
        int pm = py - 1;
        for (;pn < px + 2; ++pn) {
            for (;pm < py + 2;++pm) {
                if (map[pm][pn]->getVisual() == '.') { break; }
            }
            if (map[pm][pn]->getVisual() == '.') { break; }
        }
        newtile = new DragonHoard{};
        Tile* dragontile = new Dragon{ Posn{ pm, pn } };
        Enemy* e = dynamic_cast<Dragon*>(dragontile);
        enemies.push_back(e);
        swap(dragontile, map[pm][pn]);
        delete dragontile;
    }

    swap(newtile, map[py][px]);
    delete newtile;
}

void Game::generatorPotion() {

    int num = rand() % 6 + 1;
    Posn p = generatorpos(rand() % 5);
    Tile* newtile;
    int py = p.first;
    int px = p.second;
    if (1 == num) {
        newtile = new RH{};
        RH *rh = dynamic_cast<RH *>(newtile);
        rh->setKnowsType(false);
    }
    else if (2 == num) {
        newtile = new BA{};
        BA *ba = dynamic_cast<BA *>(newtile);
        ba->setKnowsType(false);
    }
    else if (3 == num) {
        newtile = new BD{};
        BD *bd = dynamic_cast<BD *>(newtile);
        bd->setKnowsType(false);
    }
    else if (4 == num) {
        newtile = new PH{};
        PH *ph = dynamic_cast<PH *>(newtile);
        ph->setKnowsType(false);
    }
    else if (5 == num) {
        newtile = new WA{};
        WA *wa = dynamic_cast<WA *>(newtile);
        wa->setKnowsType(false);
    }
    else if (6 == num) {
        newtile = new WD{};
        WD *wd = dynamic_cast<WD *>(newtile);
        wd->setKnowsType(false);
    }
    swap(newtile, map[py][px]);
    delete newtile;
}


void Game::setFreeze(bool b) {
    freeze = b;
}

void Game::oneTurn() {
    PC->checkSurroundings(map);
    int toRemove = -1;
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->getDead()) {
            enemies[i]->dropReward(map);
            toRemove = i;
        }
        if (!freeze && toRemove != i) {
            enemies[i]->checkSurroundings(map);
        }
    }

    if (toRemove > -1) enemies.erase(enemies.begin() + toRemove);

    PC->endTurnAction();
}

ostream& operator<<(ostream& out, Game &g) {
    for (auto i : g.map) {
        for (auto j : i) {
            cout << j->getVisual();
        }
        cout << endl;
    }

    string hero = g.PC->getName();
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