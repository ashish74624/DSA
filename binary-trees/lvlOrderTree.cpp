#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
	public:
		int data;
		node* left;
		node* right;
	
	node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

void buildTreeFromLevelOrder(node* &root){
	queue<node *> q;
	int data;
	cout<<"Enter Data for root node :"<<endl;
	cin>>data;
	root = new node(data);
	q.push(root);
	
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		
		cout<<"Enter data for left node of "<<temp->data<<" :"<<endl;
		int leftData;
		cin>>leftData;
		if(leftData != -1 ){
			temp->left= new node(leftData);
			q.push(temp->left);
		}
		
		cout<<"Enter data for right node of "<<temp->data<<" :"<<endl;
		int rightData;
		cin>>rightData;
		if(rightData != -1){
			temp->right = new node(rightData);
			q.push(temp->right);
		}
		
	}
}

void levelOrderTraversal(node* root){ // bfs
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		
		if(temp==NULL){
			cout<<endl; // ENTER
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
				
			cout<< temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			
			if(temp->right){
				q.push(temp->right);
			}
		}
		
	}
}

int main(){
	
	node* root = NULL;
	buildTreeFromLevelOrder(root);
	levelOrderTraversal(root);
	return 0;
}







