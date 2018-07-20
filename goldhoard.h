#ifndef _GOLDHOARD_H_
#define _GOLDHOARD_H_

class SmallHoard: public Gold {
//private fields
  int effect = 1;

//public methods
  void affect(PC &pc) override;
};


class NormalHoard: public Gold {
//private fields
  int effect = 2;

//public methods
  void affect(PC &pc) override;
};


class MerchantHoard: public Gold {
//private fields
  int effect = 4;

//public methods
  void affect(PC &pc) override;
};


class DragonHoard: public Gold {
//private fields
  int effect = 6;

//public methods
  void affect(PC &pc) override;
};



#endif
