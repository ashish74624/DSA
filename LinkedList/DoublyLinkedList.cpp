#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next=0;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

     ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }

};

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}

void insertAtTop(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data,int position){
    if(position==1){
        insertAtTop(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while (cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteNode(Node* &head,Node* &tail,int position){
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        } 
        if(curr->next==NULL){
            tail=curr->prev;
        }
        prev->next=curr->next;
        if(curr->next != NULL){
            curr->next->prev=prev;
        }
        curr->prev=NULL;
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(10); 
    Node* head = node1;
    Node* tail = node1;
    // print(head);
    // cout<<getLength(head)<<endl;

    insertAtTop(head,0);

    // print(head);
    // cout<<getLength(head)<<endl;
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    print(head);

    insertAtPosition(head,tail,45,1);
    print(head);
    insertAtPosition(head,tail,5,8);
    print(head);
    insertAtPosition(head,tail,6,4);
    print(head);
    deleteNode(head,tail,2);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,1);
    print(head);
    // cout<<"Start "<<head->data<<endl;
    // cout<<"Tail "<<tail->data<<endl;
}