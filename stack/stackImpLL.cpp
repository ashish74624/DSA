#include<iostream>
#include<stdio.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next=0;

        Node(int data){
            this->data=data;
            this->next=NULL;
        }

};

class Stack{
    public:
        int size;
        int pos;
        Node* top=0;

        Stack(int size){
            pos=0;
            this->size=size;
            top=NULL;
        }

        bool isFull(){
            return pos==size;
        }

        bool isEmpty(){
            return top==NULL;
        }

        void push(int data){
            if(isFull()){
                cout<<"Stack Overflow for data "<<data<<endl;
            }
            else{
                Node* temp = new Node(data);
                temp->next=top;
                top=temp;
                pos++;
                cout<<"pushed "<<data<<" in the stack"<<endl;
            }
        }

        void pop(){
            if(isEmpty()){
                cout<<"stack is empty"<<endl;
            }else{
                Node* del = top;
                top=top->next;
                cout<<"popped "<<del->data<<endl;
                delete del;
            }
        }

        int peek(){
             if(isEmpty()){
                cout<<"stack is empty"<<endl;
            }else{
                return top->data;
            }
        }


};

int main(){
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    st.pop();


}