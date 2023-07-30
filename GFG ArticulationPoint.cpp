class Solution {
  public:
  int timer=0;
    void dfs(int node,int parent,vector<int>&tin,vector<int>&low,vector<int>&vis,vector<int>&mark,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,tin,low,vis,mark,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1)mark[node]=1; //articaultion pount
                child++;
            }else{
                //means if node is visited already
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1){ //means that parent having more than 1 child(yani node 0)
         mark[node]=1; 
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>tin(V);
        vector<int>low(V);
        vector<int>vis(V,0);
        vector<int>mark(V,0);  //for marking the articulation points
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,vis,mark,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<mark.size();i++){
            if(mark[i]==1)ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};
