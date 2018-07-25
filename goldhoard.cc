#include "goldhoard.h"
#include "pc.h"

void SmallHoard::affect(PC &pc) {
  pc.beRich(*this); 
  pc.action << "PC gets SmallHoard(1). ";
}

SmallHoard::SmallHoard(): 
  Gold{} {}

SmallHoard::~SmallHoard() {}


void NormalHoard::affect(PC &pc) {
  pc.beRich(*this); 
    pc.action << "PC gets NormalHoard(2). ";
}


NormalHoard::NormalHoard(): 
  Gold{} {}

NormalHoard::~NormalHoard() {}


void MerchantHoard::affect(PC &pc) {
  pc.beRich(*this); 
    pc.action << "PC gets MerchantHoard(4). ";
}


MerchantHoard::MerchantHoard(): 
  Gold{} {}

MerchantHoard::~MerchantHoard() {}


void DragonHoard::affect(PC &pc) {
  pc.beRich(*this); 
  pc.action << "PC gets DragonHoard(6). ";
}


DragonHoard::DragonHoard(): 
  Gold{} {}

DragonHoard::~DragonHoard() {}

