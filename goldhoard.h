#ifndef _GOLDHOARD_H_
#define _GOLDHOARD_H_
#include "gold.h"

class PC;


class SmallHoard: public Gold {

public:
//public methods
  void affect(PC &pc) override;
  SmallHoard();
  ~SmallHoard();
};


class NormalHoard: public Gold {

public:
//public methods
  void affect(PC &pc) override;
  NormalHoard();
  ~NormalHoard();
};


class MerchantHoard: public Gold {

public:
//public methods
  void affect(PC &pc) override;
  MerchantHoard();
  ~MerchantHoard();
};


class DragonHoard: public Gold {

public:
//public methods
  void affect(PC &pc) override;
  DragonHoard();
  ~DragonHoard();
};



#endif
