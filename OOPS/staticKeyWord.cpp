#include<iostream>
using namespace std;

class Hero {
	
	private:
		int health;
	public:
		char level;
		char *name;
		static int timeToComplete;
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
		
		static int random(){
			return timeToComplete;
		}
		
		~Hero(){
			cout<<"Destructor called"<<endl;
		}
};

int Hero::timeToComplete=5;

int main(){
		
	cout<<Hero::timeToComplete<<endl;	
	cout<<Hero::random()<<endl;	

	return 0;
}