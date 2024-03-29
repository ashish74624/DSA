#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //Properties
    int *arr;
    int size;
    int top;

    //Behaviour
    public:
        Stack(int size){
            this->size=size;
            arr = new int[size];
            top=-1;
        }

        void push(int elem){
            if(top<size){
                top++;
                arr[top]=elem;
            }else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        void pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
            }else{
                top--;
            }
        }

        int peek() {
            if(top >=0 )
                return arr[top];
            else
            {
                cout << "Stack is Empty" << endl;
                return -1;
            }
        }

        bool empty() {
            if( top == -1) {
                return true;
            }
            else{
                return false;
            }
        }

};


int main(){
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    int t =st.peek();
    cout<<t<<endl;

}