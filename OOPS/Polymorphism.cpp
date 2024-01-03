//Compile Time Polymorphism
// Function Overloading
#include<iostream>
using namespace std;
class A
{
private:
    /* data */
public:
    void run(){
        cout<<"Hello world"<<endl;
    }
    void run(string name){
        cout<<"Hello"<<name<<endl;
    }
};

int main(){
    A obj1;

    obj1.run("Ashish");
}

