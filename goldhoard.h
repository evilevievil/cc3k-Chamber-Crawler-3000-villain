#ifndef _GOLDHOARD_H_
#define _GOLDHOARD_H_
#include "gold.h"


class SmallHoard: public Gold {

//public methods
  void affect(PC &pc) override;
};


class NormalHoard: public Gold {

//public methods
  void affect(PC &pc) override;
};


class MerchantHoard: public Gold {

//public methods
  void affect(PC &pc) override;
};


class DragonHoard: public Gold {

//public methods
  void affect(PC &pc) override;
};



#endif
