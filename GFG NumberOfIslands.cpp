class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid,int i,int j){
        grid[i][j]='0';
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> v={{0,1},{0,-1},{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1}};
        for(int k=0;k<v.size();k++){
            int x=i+v[k].first;
            int y=j+v[k].second;
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
