#include <string>
#include <iomanip>
#include <pair>

class Shade{
	Pair <int, int> position;
	int hp, atk, def;
	char sym;

	protected:
		int getHp();
		void setHp();
		int getAtk();
		int getDef();
		
	public:
		void move() override;
		void checkSurroundings();
		Shade();
		~Shade();
}