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
  pc.action << "PC consumed RH potion";
}

RH::RH(): Potion{} {}
RH::~RH() {}

RH::std::string beSpotted() override {
  RH::knowsType? return "RH potion" : return "Unknown potion";
}

//BA
void BA::affect(PC &pc) {
  pc.beAffected(*this);
  BA::knowsType = true;  
  pc.action << "PC consumed BA potion";
}


BA::BA(): Potion{} {}
BA::~BA() {}

BA::std::string beSpotted() override {
  BA::knowsType? return "BA potion" : return "Unknown potion";
}

//BD
void BD::affect(PC &pc) {
  pc.beAffected(*this);
  BD::knowsType = true;  
  pc.action << "PC consumed BD potion";
}


BD::BD(): Potion{} {}
BD::~BD() {}

BD::std::string beSpotted() override {
  BD::knowsType? return "BD potion" : return "Unknown potion";
}


//PH
void PH::affect(PC &pc) {
  pc.beAffected(*this);
  PH::knowsType = true;  
  pc.action << "PC consumed PH potion";
}


PH::PH(): Potion{} {}
PH::~PH() {}

PH::std::string beSpotted() override {
  PH::knowsType? return "PH potion" : return "Unknown potion";
}


//WA
void WA::affect(PC &pc) {
  pc.beAffected(*this);
  WA::knowsType = true;  
  pc.action << "PC consumed WA potion";
}


WA::WA(): Potion{} {}
WA::~WA() {}

WA::std::string beSpotted() override {
  WA::knowsType? return "WA potion" : return "Unknown potion";
}


//WD
void WD::affect(PC &pc) {
  pc.beAffected(*this);
  WD::knowsType = true;  
  pc.action << "PC consumed WD potion";
}


WD::WD(): Potion{} {}
WD::~WD() {}

WD::std::string beSpotted() override {
  WD::knowsType? return "WD potion" : return "Unknown potion";
}

