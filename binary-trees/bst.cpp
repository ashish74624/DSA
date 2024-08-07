#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
}; 

Node* constructBST(Node* root, int data) {
    // base case
    if (!root) {
        root = new Node(data);
        return root;
    }
    
    if (data > root->data) {
        root->right = constructBST(root->right, data);
    } else {
        root->left = constructBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    
    while (data != -1) {
        root = constructBST(root, data);
        cout << "Enter data (-1 to stop): ";
        cin >> data;
    }
}

void print(Node* root) { // bfs
    if (!root) return; // Edge case: if the tree is empty
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp == NULL) {
            cout << endl; // ENTER
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root){
	Node* temp=root;
	
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

Node* maxVal(Node* root){
	Node* temp=root;
	
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}

int main() {
    Node* root = NULL;
    cout << "Enter data to create a BST" << endl;
    takeInput(root);
    print(root);
    Node* minValNode = minVal(root);
    Node* maxValNode = maxVal(root);
    cout<<"The min val in BST is "<<minValNode->data<<endl;
    cout<<"The max val in BST is "<<maxValNode->data<<endl;
    return 0;
}
