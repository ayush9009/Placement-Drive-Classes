class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int helper(Node* root,int &maxi){
        if(root==NULL)return 0;
        auto ls=max(0,helper(root->left,maxi));
        auto rs=max(0,helper(root->right,maxi));
        
        maxi=max(maxi,root->data+ls+rs);
        
        // maxi=max(maxi,root->data+max(ls,rs)); ye ni kar sakte ,kuki iske liye run karo 10 2 5 N N N -2
        // to maxi=15 ayega lakin ana chaiye 17 ye test case kai loiye maxi=max(maxi,root->data+ls+rs) kara hua
        return root->data+max(ls,rs);
        
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};
