//Compile Time Polymorphism
// Operator Overloading
#include<iostream>
using namespace std;

class A{
    public:
    int a;
    int b;

    void operator+ (A &obj){
        int val1= this->a;
        int val2 = obj.a;
        cout<<"Output = "<< val1-val2 <<endl;
    }

};

int main(){
    A obj1,obj2;

    obj1.a=4;
    obj2.a=1;

    obj1 + obj2;
}