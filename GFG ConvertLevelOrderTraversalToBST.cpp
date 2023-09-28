Node* helper(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        root->left=root->right=NULL;
        return root;
    }
    if(data <= root->data)root->left=helper(root->left,data);
    else root->right=helper(root->right,data);
    return root;
}
Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=helper(root,arr[i]);
    }
    return root;
}
