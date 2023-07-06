class Solution {
public:

//simply dfs with simple backtracking
//for understanding better please do dry run once
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]<=0)return 0;
        grid[i][j]=-grid[i][j];
        int res=max({dfs(grid,i,j+1),dfs(grid,i+1,j),dfs(grid,i-1,j),dfs(grid,i,j-1)});
        grid[i][j]=-grid[i][j];// backtrack
        return grid[i][j]+res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res=max(res,dfs(grid,i,j));
            }
        }
        return res;
    }
};
