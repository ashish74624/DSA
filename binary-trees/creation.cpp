#include<iostream>
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

int main(){
    
    node* root=NULL;
    root=buildTree(root);

}