class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
     vector<vector<int>>ans;
    int timer=0;
    void dfs(int node,int parent,vector<int>&disc,vector<int>&vis,vector<int>&low,vector<int>adj[]){
        vis[node]=1;
        low[node]=disc[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,disc,vis,low,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>disc[node]){
                    ans.push_back({it,node});
                }
            }else{  //means if the node is already visited
                 low[node]=min(low[node],disc[it]);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
       
        vector<int>disc(V);
        vector<int>vis(V,0);
        vector<int>low(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,disc,vis,low,adj);
            }
        }
        int flag=0;
        for(auto it:ans){
            int x=it[0];
            int y=it[1];
            if((x==c && y==d) || (x==d && y==c)){
                flag=1;
                break;
            }
        }
        return flag;
        // return ans;
    }
};
