#include "potiontype.h"

void RH::affect(PC &pc) {
  pc.beAffected(*this);
}

RH::RH(): Potion{} {}
RH::~RH() {}


void BA::affect(PC &pc) {
  pc.beAffected(*this);
}


BA::BA(): Potion{} {}
BA::~BA() {}


void BD::affect(PC &pc) {
  pc.beAffected(*this);
}


BD::BD(): Potion{} {}
BD::~BD() {}


void PH::affect(PC &pc) {
  pc.beAffected(*this);
}


PH::PH(): Potion{} {}
PH::~PH() {}


void WA::affect(PC &pc) {
  pc.beAffected(*this);
}


WA::WA(): Potion{} {}
WA::~WA() {}


void WD::affect(PC &pc) {
  pc.beAffected(*this);
}


WD::WD(): Potion{} {}
WD::~WD() {}
