class Solution
{
    public:
        Node* insert(Node* root, int data) {
        
            // Your code goes here
            if(root==NULL)return new Node(data);
            if(root->data==data)return root;
            
            if(data<root->data)root->left=insert(root->left,data);
            else root->right=insert(root->right,data);
            
            return root;
    }

};
