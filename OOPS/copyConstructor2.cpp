#include<iostream>
using namespace std;

class Hero {
	
	private:
		int health;
	public:
		char level;
		char *name;
		Hero(){
			name = new char[100];
			
		}
		
		void print(){
			cout<<"Name = "<< this->name<<endl;
			cout<<"Health = "<< this->health<<endl;
			cout<<"Level = "<< this->level<<endl;
		}
		int getHealth(){
			return health;
		}
		
		void setHealth(int h){
			health = h;
		}	
		
		void setName(char name[]){
			strcpy(this->name,name);
		}	
		
		// Custom copy constructor -- doing deep copy
		Hero( Hero& temp){ // Use Pass by refence
			char *ch = new char[strlen(temp.name)+1];
			strcpy(ch,temp.name);
			this->name=ch;
			
			this->health = temp.health;
			this->level= temp.level;
			
		}
		
		~Hero(){
			cout<<"Destructor called"<<endl;
		}
};

int main(){
	
	Hero h1;
	h1.level='A';
	h1.setHealth(80);
	char name[10] = "John Doe";
	h1.setName(name);
	Hero h2(h1);
	h1.name[0]='A';
//	h1=h2;
	h1.print();
	h2.print();
	
	Hero *b = new Hero;
	delete b;
	return 0;
}