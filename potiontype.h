#ifndef _POTIONTYPE_H_
#define _POTIONTYPE_H_
#include "potion.h"
#include "testpc.h"

class RH: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  RH();
  ~RH();
};


class BA: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  BA();
  ~BA();
};


class BD: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  BD();
  ~BD();
};


class PH: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  PH();
  ~PH();
};



class WA: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  WA();
  ~WA();
};


class WD: public Potion {

public:
//public methods
  void affect(PC &pc) override;
  WD();
  ~WD();
};

#endif
