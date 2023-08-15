/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(helper(root->left),helper(root->right));
    }
    void helper(TreeNode* root,vector<vector<string>>&result,int h,int row,int col){
        if(root==NULL)return;
        result[row][col]=to_string(root->val);  //root node
        int lc=col-pow(2,h-row-2);
        int rc=col+pow(2,h-row-2);

        if(root->left)result[row+1][lc]=to_string(root->left->val);
        if(root->right)result[row+1][rc]=to_string(root->right->val);

        helper(root->left,result,h,row+1,lc);
        helper(root->right,result,h,row+1,rc);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=helper(root);
        // int n=h+1;
        int m=pow(2,h)-1;
        vector<vector<string>>result(h,vector<string>(m,""));
        if(root==NULL)return result;
        int row=0;
        int col=(m-1)/2;
        helper(root,result,h,row,col);
        return result;
    }
};
