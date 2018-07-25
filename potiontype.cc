#include "potiontype.h"
#include "pc.h"

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
  pc.action << "PC consumed RH potion";
}

RH::RH(): Potion{} {}
RH::~RH() {}

std::string RH::beSpotted() {
  return RH::knowsType? "RH potion" : "Unknown potion";
}

//BA
void BA::affect(PC &pc) {
  pc.beAffected(*this);
  BA::knowsType = true;  
  pc.action << "PC consumed BA potion";
}


BA::BA(): Potion{} {}
BA::~BA() {}

std::string BA::beSpotted() {
  return BA::knowsType?  "BA potion" :  "Unknown potion";
}

//BD
void BD::affect(PC &pc) {
  pc.beAffected(*this);
  BD::knowsType = true;  
  pc.action << "PC consumed BD potion";
}


BD::BD(): Potion{} {}
BD::~BD() {}

std::string BD::beSpotted() {
  return BD::knowsType? "BD potion" : "Unknown potion";
}


//PH
void PH::affect(PC &pc) {
  pc.beAffected(*this);
  PH::knowsType = true;  
  pc.action << "PC consumed PH potion";
}


PH::PH(): Potion{} {}
PH::~PH() {}

std::string PH::beSpotted() {
  return PH::knowsType? "PH potion" : "Unknown potion";
}


//WA
void WA::affect(PC &pc) {
  pc.beAffected(*this);
  WA::knowsType = true;  
  pc.action << "PC consumed WA potion";
}


WA::WA(): Potion{} {}
WA::~WA() {}

std::string WA::beSpotted() {
  return WA::knowsType? "WA potion" : "Unknown potion";
}


//WD
void WD::affect(PC &pc) {
  pc.beAffected(*this);
  WD::knowsType = true;  
  pc.action << "PC consumed WD potion";
}


WD::WD(): Potion{} {}
WD::~WD() {}

std::string WD::beSpotted() {
  return WD::knowsType? "WD potion" : "Unknown potion";
}

