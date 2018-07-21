#include <string>
#include <iomanip>

class Race{
	int x, y, hp, atk, def;
	char sym;

	protected:
		int getHp();
		void setHp();
		int getAtk();
		int getDef();
		int getGold();
		void setGold();
	public:
		Race();
		virtual ~Race()=0;

}