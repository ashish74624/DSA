#include<iostream>
#include<map>
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

bool detectLoop(Node* head){
	if(head==NULL){
		return false;
	}
	
	map<Node*,bool> visited;
	
	Node* temp=head;
	
	while(temp!=NULL){
		if(visited[temp]==true){
			cout<<"Loop detected on element "<<temp->data<<endl;
			return true;
		}else{
			visited[temp]=true;
			temp=temp->next;
		}
	}
	return false;
}

Node* floydDetectionLoop(Node* head){
	if(head==NULL){
		return NULL;
	}
	Node* slow=head;
	Node* fast=head;
	
	while(slow!=NULL && fast!=NULL){
		
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
		if(slow==fast){
			return slow;
		}
	}
	return NULL;
}

Node* getStartingPoint(Node* head){
	if(head==NULL){
		return NULL;
	}
	
	Node* intersection = floydDetectionLoop(head);
	
	Node* slow=head;
	
	while(slow!=intersection){
		slow=slow->next;
		intersection=intersection->next;
	}
	
	return slow;
}

void removeLoop(Node* head){
	if(head==NULL){
		return;
	}
	
	Node* startOfLoop = getStartingPoint(head);
	Node* temp= startOfLoop;
	
	while(temp->next!=startOfLoop){
		temp=temp->next;
	}
	
	temp->next=NULL;
	
}


int main(){
    Node* node1 = new Node(10); // Dynamic initialization of object

    //Creating start pointer node1
    Node* start = node1;
    Node* tail = node1;
    insertAtEndWithTail(tail,20);
    insertAtEndWithTail(tail,40);
    insertMiddle(start,tail,30,3);
//    deleteNode(start,tail,4);
//    cout<<"----"<<endl;
//    cout<<"Start "<<start->data<<endl;
//    cout<<"Tail "<<tail->data<<endl;

	tail->next=start->next;
	
	if(floydDetectionLoop(start) !=NULL){
		cout<<"Loop Detected at "<<floydDetectionLoop(start)->data<<endl;
	}else{
		cout<<"No Loops found"<<endl;
	}

	Node* h=getStartingPoint(start);
	cout<<"Starting at "<<h->data<<endl;
	removeLoop(start);
    print(start);
}














