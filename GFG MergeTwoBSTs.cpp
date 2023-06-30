class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int>result;
    
    // void createBST()
    vector<int> merge(Node *root1, Node *root2)
    {
       
       //Your code here
       queue<Node*>q,q2;
       q.push(root1);
       while(!q.empty()){
           Node* cur=q.front();
           q.pop();
           result.push_back(cur->data);
           if(cur->left)q.push(cur->left);
           if(cur->right)q.push(cur->right);
       }
       q2.push(root2);
       while(!q2.empty()){
           Node* cur=q2.front();
           q2.pop();
           result.push_back(cur->data);
           if(cur->left)q2.push(cur->left);
           if(cur->right)q2.push(cur->right);
       }
    
       sort(result.begin(),result.end());
       return result;
       
    }
};
