#include <iomanip>
#include <pair>

class Vampire{
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
		void attack(Race *victim) override;
		void beAttacked(Race *victim) override;
		void checkSurroundings(vector<vector <Tile*>> &map);
		Vampire();
		~Vampire();
}