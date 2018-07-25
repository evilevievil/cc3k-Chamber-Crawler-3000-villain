#ifndef _POTIONTYPE_H_
#define _POTIONTYPE_H_
#include "potion.h"

class PC;


class RH: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  RH();
  ~RH();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};


class BA: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  BA();
  ~BA();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};


class BD: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  BD();
  ~BD();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};


class PH: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  PH();
  ~PH();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};



class WA: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  WA();
  ~WA();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};


class WD: public Potion {

protected: 
  static bool knowsType;

public:
//public methods
  void affect(PC &pc) override;
  WD();
  ~WD();
  std::string beSpotted() override;
  static void setKnowsType(bool b);
};

#endif
