#include "goldhoard.h"

void Tile::Item::Gold::SmallHoard::affect(PC &pc) {
  pc.beAffected(*this); 
}


void Tile::Item::Gold::NormalHoard::affect(PC &pc) {
  pc.beAffected(*this); 
}


void Tile::Item::Gold::MerchantHoard::affect(PC &pc) {
  pc.beAffected(*this); 
}


void Tile::Item::Gold::DragonHoard::affect(PC &pc) {
  pc.beAffected(*this); 
}



