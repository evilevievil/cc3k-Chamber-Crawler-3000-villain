#include <string>
#include <iomanip>

class Enemy{
	int hp, atk, def;
	char sym;

	protected:
		getHp();
		setHp();
		getAtk();
		getDef();
		
	public:
		void checkSurroundings();
		
		Enemy();
		virtual ~Enemy();
}