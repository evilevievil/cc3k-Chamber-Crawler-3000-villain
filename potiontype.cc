#include "potiontype.h"

void Tile::Item::Potion::RH::affect(PC &pc) {
  pc.beAffected(*this);
}


void Tile::Item::Potion::BA::affect(PC &pc) {
  pc.beAffected(*this);
}


void Tile::Item::Potion::BD::affect(PC &pc) {
  pc.beAffected(*this);
}


void Tile::Item::Potion::PH::affect(PC &pc) {
  pc.beAffected(*this);
}


void Tile::Item::Potion::WA::affect(PC &pc) {
  pc.beAffected(*this);
}


void Tile::Item::Potion::WD::affect(PC &pc) {
  pc.beAffected(*this);
}
