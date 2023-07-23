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
    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<TreeNode*>result;
        if(n%2==0)return {};
        if(n==1)return {new TreeNode(0)};
        if(mp.find(n)!=mp.end())return mp[n];
        for(int i=1;i<n;i+=2){  // i=1 hai i+=2,isliye kuki fullBinaryTreesmai no.ofnodes odd hi honge tabhi vo full bnega
           auto leftSubTree=allPossibleFBT(i);
           auto rightSubTree=allPossibleFBT(n-i-1);//n-i-1 kuki observations,agr n=7 to left mai ek node aur right mai 5 nodes pssble h
           for(auto leftNode:leftSubTree){
               for(auto rightNode:rightSubTree){
                   result.push_back(new TreeNode(0,leftNode,rightNode));
               }
           }
        }
        return mp[n]=result;
    }
};
