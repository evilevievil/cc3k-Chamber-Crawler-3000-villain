#include <string>
#include <iomanip>

class PC{
	int hp, atk, def;
	char sym;

	protected:
		getHp();
		setHp();
		getAtk();
		getDef();
		
	public:
		Race();
		virtual ~Race();
}