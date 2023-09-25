class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here 
        vector<int>ans;
        if(root==NULL)return ans;
       
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            Node* cur=it.first;
            int line=it.second;
            
            if(mp.find(line)==mp.end())mp[line]=cur->data;
            if(cur->left)q.push({cur->left,line-1});
            if(cur->right)q.push({cur->right,line+1});
            
        }
        // for(auto it:mp){
        //     cout<<it.first<<" ";
        // }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }

};
