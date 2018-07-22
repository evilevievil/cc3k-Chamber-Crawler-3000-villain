#ifndef _POTIONTYPE_H_
#define _POTIONTYPE_H_

class RH: public Potion {

//public methods
  void affect(PC &pc) override;
};


class BA: public Potion {

//public methods
  void affect(PC &pc) override;
};


class BD: public Potion {

//public methods
  void affect(PC &pc) override;
};


class PH: public Potion {

//public methods
  void affect(PC &pc) override;
};



class WA: public Potion {

//public methods
  void affect(PC &pc) override;
};


class WD: public Potion {

//public methods
  void affect(PC &pc) override;
};

#endif
