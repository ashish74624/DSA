#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main(){

    stack<int> s;

    //push
    s.push(2);
    s.push(3);

    cout<<"Top Element : "<<s.top()<<endl;

    //pop
    s.pop();

    //check again
    cout<<"Top Element : "<<s.top()<<endl;

    if(s.empty()) {
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout<<"Stack size : "<<s.size()<<endl;

}