#ifndef _POTIONTYPE_H_
#define _POTIONTYPE_H_

class RH: public Potion {
//private fields
  int effect = 10;

//public methods
  void affect(PC &pc) override;
};


class BA: public Potion {
//private fields
  int effect = 5;

//public methods
  void affect(PC &pc) override;
};


class BD: public Potion {
//private fields
  int effect = 5;

//public methods
  void affect(PC &pc) override;
};


class PH: public Potion {
//private fields
  int effect = -10;

//public methods
  void affect(PC &pc) override;
};



class WA: public Potion {
//private fields
  int effect = -5;

//public methods
  void affect(PC &pc) override;
};


class WD: public Potion {
//private fields
  int effect = -5;

//public methods
  void affect(PC &pc) override;
};

#endif
