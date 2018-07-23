#include "goldhoard.h"

void SmallHoard::affect(PC &pc) {
  pc.beRich(*this); 
}

SmallHoard::SmallHoard(): 
  Gold{} {}

SmallHoard::~SmallHoard() {}


void NormalHoard::affect(PC &pc) {
  pc.beRich(*this); 
}


NormalHoard::NormalHoard(): 
  Gold{} {}

NormalHoard::~NormalHoard() {}


void MerchantHoard::affect(PC &pc) {
  pc.beRich(*this); 
}


MerchantHoard::MerchantHoard(): 
  Gold{} {}

MerchantHoard::~MerchantHoard() {}


void DragonHoard::affect(PC &pc) {
  pc.beRich(*this); 
}


DragonHoard::DragonHoard(): 
  Gold{} {}

DragonHoard::~DragonHoard() {}

