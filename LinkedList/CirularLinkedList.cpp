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

void insertTop(Node* &tail,int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail=newNode;
        tail->next=newNode;
    }
    else{
        Node* forward=tail->next;
        newNode->next=forward;
        tail->next=newNode;
    }

}

void print(Node* tail) {
    //empty list
    if (tail == NULL) {
        cout << "List is Empty " << endl;
        return;
    }

    Node* temp = tail->next;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << endl;
}


void insertAtTail(Node* &tail,int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail=newNode;
        tail->next=newNode;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}

void insertAtPosition(Node* &tail, int position, int data) {
    if (position == 1) {
        insertTop(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* curr = tail->next;
    int cnt = 1;

    while (cnt < position - 1) {
        curr = curr->next;
        cnt++;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    // Update tail if the new node is inserted at the last position
    if (newNode->next == tail->next) {
        tail = newNode;
    }
}

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}  

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircular(Node* head){
	if(head==NULL){
		return true;
	}
//	cout<<"issue"<<endl;
	Node* temp=head->next;
	while(temp!=NULL && temp!=head){
		temp=temp->next;
	}
	if(temp==head){
		return true;
	}
		return false;
	
	
}



int main(){
    Node* tail = NULL;
    // print(tail);
    insertTop(tail,20);
    // print(tail);
    insertTop(tail,10);
    // print(tail);
    insertTop(tail,0);
    // print(tail);
    insertAtTail(tail,30);
    // print(tail);
//    insertAtPosition(tail,1,500);
//    // print(tail);
//    insertAtPosition(tail,6,40);
//    print(tail);
//    deleteNode(tail,10);
    print(tail);
//    cout<<"Tail "<<tail->data<<endl;
	if(isCircular(tail)){
		cout<<"It is Circular"<<endl;
	}else{
		cout<<"Not circular"<<endl;
	}

    return 0;
}