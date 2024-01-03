#include<iostream>
using namespace std;

class Hero {
	
	
	
	private:
		int health;
	public:
		Hero(){
			cout<< "Constructor called" << endl;
		}
		
		Hero(int health){
//			cout<< "Constructor called" << endl;
			this -> health = health;
		}
		char level;
		
		int getHealth(){
			return health;
		}
		
		void setHealth(int h){
			health = h;
		}	
};

int main(){
	
	Hero h1(50);// statically
	
//	Hero *h1 = new Hero(40);// dynamically
	
//	h1.setHealth(70);
	h1.level= 'A';
//	h1->level= 'A';
	
	cout << "Health = " << h1.getHealth() << endl;	
//	cout << "Health = " << h1->getHealth() << endl;	
	cout << "Level = " << h1.level << endl;	
//	cout << "Level = " << h1->level << endl;	
	return 0;
}