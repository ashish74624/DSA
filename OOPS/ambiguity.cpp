#include<iostream>
using namespace std;

class A
{
private:
    /* data */
public:
    void abc(){
        cout<<"abc in A"<<endl;
    }
};

class B
{
private:
    /* data */
public:
    void abc(){
        cout<<"abc in B"<<endl;
    }
};

class C : public A , public B{

};

int main(){

    C obj1;

    // obj1.abc();
    obj1.A::abc();
}