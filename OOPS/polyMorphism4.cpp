#include<iostream>
using namespace std;

class Emp{
	private:
		string Name;
		int Age;
		string Gender;
	public:
		void setName(string name){
			Name = name;
		}	
		
		string getName(){
			return Name;
		}
		
		Emp(string name,int age,string gender){
			Name = name;
			Age = age;
			Gender = gender;
		}
};

class Dev:Emp{
	public :
		string FavLang;
		
		Dev()
};

int main(){
	Emp e1("Ashish1",22,"Male") ;
//	e1.setName("Ashish");
	
	Dev d("Aman",25,"female");
	
	cout<< e1.getName();
}