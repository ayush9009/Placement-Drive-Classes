class Solution {
public:
    const int mod = 1000000007;
    int dfs(vector<vector<int>>& grid, int k,int row,int col,int sum , vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=n || col>=m  )return 0;
        if(row==n-1 && col==m-1){ //means reach to end
            if((sum+grid[row][col])%k==0){
                return 1;
            }
            return 0;
        }
        // row,col,sum ye teeno change hore isliye 3d dpmatrix leni padi
        if(dp[row][col][sum%k]!=-1)return dp[row][col][sum%k];

        int x=dfs(grid,k,row+1,col,sum+grid[row][col],dp)%mod; //bottom direction
        int y=dfs(grid,k,row,col+1,sum+grid[row][col],dp)%mod; //right direction
        //  ek path jaga x (bottom direction) to is direction kai jitne bhi path
        //  unki count x mai aise hi y mai right diection vale sabhi path ki count
        // dp[x][y][sum%k] //it contains the count ofpossibelpathaccoringtoquestn
        return dp[row][col][sum%k]=(x+y)%mod;


    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return dfs(grid,k,0,0,0,dp)%mod;
    }
};
