#include "enemy.h"
#include <rand>

Enemy::Enemy(char c, Posn p, Tile* t, int maxhp, int hp, int atk, int def):
  Race{c, p, t, maxhp, hp, atk, def} {}

void Enemy::dropReward(){
}

void Enemy::beAttacked(PC& pc){
  hp -= damage(pc.getAtk(), def);
  if(hp <= 0) dropReward();
}

void Enemy::beAttacked(Vampire& pc){
  hp -= damage(pc.getAtk(), def);
  pc.restoreHp();
  if(hp <= 0) dropReward();
}

void Enemy::beAttacked(Goblin& pc){
  hp -= damage(pc.getAtk(), def);
  if(hp <= 0){
    pc.addGold(5);
    dropReward();
  }
}


void Enemy::checkSurroundings(){
}

void Enemy::randMove(Map& map){
}
