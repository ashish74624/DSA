//Run Time Polymorphism
// Method Overloading
#include<iostream>
using namespace std;

class Animal
{
private:
    /* data */
public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class DOG : public Animal
{
private:
    /* data */
public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};

int main(){
    DOG d;

    d.speak();
}