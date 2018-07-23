#ifndef _FLOOR_H_
#define _FLOOR_H_

class FloorLevel{
protected:
	int level;
public:
	FloorLevel();
	~FloorLevel();
  virtual void generator() = 0;
};

#endif
