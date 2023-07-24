class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
    vector<int>result;
    if (!root)
        return result;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {   
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the right most element
            // at the level
            if (i == n)
                result.push_back(temp->data);
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return result;
}
};
