#include<iostream>
using namespace std;

class Hero {
	
	private:
		int health;
	public:
		char level;
		
		Hero(int health,char level){
			this->health = health;
			this->level = level;
		}
		
		void print(){
			cout<<"Health = "<< this->health<<endl;
			cout<<"Level = "<< this->level<<endl;
		}
		int getHealth(){
			return health;
		}
		
		void setHealth(int h){
			health = h;
		}	
		
		// Custom copy constructor
		Hero( Hero& temp){ // Use Pass by refence
			cout<<"Copy constructor called" <<endl;
			this->health = temp.health;
			this->level = temp.level;
		}
};

int main(){
	
	Hero h1(80,'A');
	h1.print();
	
//	Copy contructor called
	Hero h2(h1);
	h2.print();
	return 0;
}