#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

class Textdisplay{
  const vector<vector<tile*>>* map;
  PC& pc;

public:
  Textdisplay(vector<vector<tile*>>* map, PC& pc);
  friend ostream& operator<<(ostream& out, Textdisplay td);

};

ostream& operator<<(ostrea& out, Textdisplay td);
#endif
