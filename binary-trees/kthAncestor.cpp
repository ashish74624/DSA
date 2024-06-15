int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(root==NULL){
        return -1;
    }
    
    unordered_map<int,int> parent; // node & their parent
    parent[root->data] = -1 ; // No parent for root
    
    queue<Node*> q;
    q.push(root);
    
    //did it for the whole tree
    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        
        if(currNode->left){
            q.push(currNode->left);
            parent[currNode->left->data]= currNode->data;
        }
        
        if(currNode->right){
            q.push(currNode->right);
            parent[currNode->right->data]= currNode->data;
        }
    }
    
    int curr = node;
    
    while(k>0 && curr!=-1){
        curr= parent[curr];
        k--;
    }
    
    return curr;
    
}