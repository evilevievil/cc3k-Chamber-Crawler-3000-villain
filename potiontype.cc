#include "potiontype.h"

bool RH::knowsType = false;
bool BA::knowsType = false;
bool BD::knowsType = false;
bool PH::knowsType = false;
bool WA::knowsType = false;
bool WD::knowsType = false;

//RH
void RH::affect(PC &pc) {
  pc.beAffected(*this);
  RH::knowsType = true;  
}

RH::RH(): Potion{} {}
RH::~RH() {}

RH::std::string beSpotted() {
  RH::knowsType? return "RH potion" : return "Unknown"
}

//BA
void BA::affect(PC &pc) {
  pc.beAffected(*this);
  BA::knowsType = true;  
}


BA::BA(): Potion{} {}
BA::~BA() {}

BA::std::string beSpotted() {
  BA::knowsType? return "BA potion" : return "Unknown"
}

//BD
void BD::affect(PC &pc) {
  pc.beAffected(*this);
  BD::knowsType = true;  
}


BD::BD(): Potion{} {}
BD::~BD() {}

BD::std::string beSpotted() {
  BD::knowsType? return "BD potion" : return "Unknown"
}


//PH
void PH::affect(PC &pc) {
  pc.beAffected(*this);
  PH::knowsType = true;  
}


PH::PH(): Potion{} {}
PH::~PH() {}

PH::std::string beSpotted() {
  PH::knowsType? return "PH potion" : return "Unknown"
}


//WA
void WA::affect(PC &pc) {
  pc.beAffected(*this);
  WA::knowsType = true;  
}


WA::WA(): Potion{} {}
WA::~WA() {}

WA::std::string beSpotted() {
  WA::knowsType? return "WA potion" : return "Unknown"
}


//WD
void WD::affect(PC &pc) {
  pc.beAffected(*this);
  WD::knowsType = true;  
}


WD::WD(): Potion{} {}
WD::~WD() {}

WD::std::string beSpotted() {
  WD::knowsType? return "WD potion" : return "Unknown"
}

