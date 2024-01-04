#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next=0;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtTop(Node* &start, int newData){
    //Creating a new node
    Node* temp = new Node(newData);
    temp->next = start;// Here start is pointing to the node1 ,,, then we change it
    start = temp;// moving start from node1 to temp
}

void print(Node* &start){
    Node* temp= start;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<endl;
    // cout<<temp<<endl;
}

void insertAtEndWithTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next= temp;
    tail=temp;
}

void insertMiddle(Node* &start,Node* &tail,int data,int position){

    if(position==1){
        insertAtTop(start,data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp=start;
    int cnt =1;
    while(cnt<position-1){
        temp= temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtEndWithTail(tail,data);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteNode(Node* &start,Node* &tail,int position){
    //Deleting the first Node
    if(position==1){
        Node* temp = start;
        start=start->next;
        //delete the memory
        temp->next=NULL;
        delete temp;
    }else{
        //For middle of last elem
        Node* curr = start;
        Node* prev=NULL;
        int cnt=1;
        while (cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        //DEALLOC MEMORY
        curr->next=NULL;
        delete curr;
    }
}


int main(){
    Node* node1 = new Node(10); // Dynamic initialization of object

    //Creating start pointer node1
    Node* start = node1;
    Node* tail = node1;
    // insertAtTop(start,50);
    insertAtEndWithTail(tail,20);
    print(start);
    insertAtEndWithTail(tail,40);
    print(start);
    insertMiddle(start,tail,30,3);
    print(start);
    deleteNode(start,tail,4);
    print(start);
    cout<<"----"<<endl;
    cout<<"Start "<<start->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

}