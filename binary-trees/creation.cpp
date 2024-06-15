#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class node {
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter data for the node :"<<endl;
    cin>>data;
    
    if(data == -1){
        return NULL;
    }
    
    root = new node(data);

    cout<<"Enter data for left node of "<<data<<endl;
    root->left = buildTree(root->left);    
    cout<<"Enter data for right node of "<<data<<endl;
    root->right = buildTree(root->right);    
    return root;
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

void reverseLevelOrderTraversal(node* root){
	queue<node*> q;
	stack<node*> s;
	q.push(root);
	
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		s.push(temp);
		
		if(temp->right){
			q.push(temp->right);
		}
		
		if(temp->left){
			q.push(temp->left);
		}
		
	}
	
	while(!s.empty()){
		node* t = s.top();
		cout<<t->data<<" ";
		s.pop();
		
	}
	
	cout<<endl;
	
}


void inorder(node* root){ //L N R
	// base case
	if(root==NULL){
		return;
	}
	
	inorder(root->left); // L
	cout<<root->data<<endl; // N
	inorder(root->right); // R
}


void preorder(node* root){ //N L R
	// base case
	if(root==NULL){
		return;
	}
	
	cout<<root->data<<endl; // N
	preorder(root->left); // L
	preorder(root->right); // R
}

void postorder(node* root){ // L R N
	// base case
	if(root==NULL){
		return;
	}
	
	postorder(root->left); // L
	postorder(root->right); // R
	cout<<root->data<<endl; // N
}


int main(){
    
    node* root=NULL;
    
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(root);
    
    cout<<"Reverse Level Order Traversal"<<endl;
    reverseLevelOrderTraversal(root);

	cout<<"Inorder Traversal"<<endl;
	inorder(root);
	
	cout<<"Preorder Traversal"<<endl;
	preorder(root);
	
	cout<<"Postorder Traversal"<<endl;
	postorder(root);

}








