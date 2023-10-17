class Solution {
public:
    void dfs(int root,vector<int>& leftchild, vector<int>& rightchild,vector<int>&visited){
        if(visited[root])return;
        visited[root]=true;
        if(leftchild[root]!=-1)dfs(leftchild[root],leftchild,rightchild,visited);
        if(rightchild[root]!=-1)dfs(rightchild[root],leftchild,rightchild,visited);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) {
        vector<int>visited(n,0);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftchild[i]!=-1)indegree[leftchild[i]]++;
            if(rightchild[i]!=-1)indegree[rightchild[i]]++;
        }
        //for a valid tree every nodes,every node except must have one indegree
        for(int i=0;i<n;i++){
            if(indegree[i]>=2)return false;
        }
        int root_node=-1;
        int root_cnt=0;
        //for a valid directed tree,there is only one parent i.e indegree[root]==0 sirf ek hi parent hoga
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                root_cnt++;
                root_node=i;
            }
        }
        if(root_cnt!=1)return false;
        //discconnected nodes kai liye dfs call kardiya
        //agr koi bad mai not visited then return false
        dfs(root_node,leftchild,rightchild,visited);
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    }
};
