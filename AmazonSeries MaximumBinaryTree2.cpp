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

    TreeNode* insertIntoMaxTree(TreeNode* root, int x) {
      if(root==NULL)return new TreeNode(x);

      else if(root->val < x){
          TreeNode* temp=new TreeNode(x);
          temp->left=root;
          return temp;
      }else{
          root->right= insertIntoMaxTree(root->right,x);
          return root;
      }
    
    }
};
