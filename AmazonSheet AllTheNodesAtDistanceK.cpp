class Solution
{
private:

public:
// VVIP QUESTION YAHA GRAPH BUILD KARE BINA KARNA KAFI MUSHKIL HAI MOST MOST MOST IMPORTANT QUESTION
    void helper(Node* root,unordered_map<int,vector<int>>&graph){
        if(root->left!=NULL){
            graph[root->data].push_back(root->left->data);
            graph[root->left->data].push_back(root->data);
            helper(root->left,graph);
        }
        if(root->right!=NULL){
            graph[root->data].push_back(root->right->data);
            graph[root->right->data].push_back(root->data);
            helper(root->right,graph);
        }
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        if(k==0){
            return {root->data};
        }
        unordered_map<int,vector<int>>graph;
        unordered_map<int,bool>vis;
        helper(root,graph);
        queue<int>q;
        vector<int>res;
        int cnt=0;
        q.push(target);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int cur=q.front();
                q.pop();
                vis[cur]=1;
                for(auto it:graph[cur]){
                    if(!vis[it])q.push(it);
                }
            }
            cnt++;
            if(cnt==k){  //means all the nodes  at this level are of required distance
                while(q.empty()==false){
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
