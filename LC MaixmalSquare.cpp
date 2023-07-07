class Solution {
public:
// TC:O(m*n)
//question is easy lakin thoda aapko question ko dhyan se dekna hoga,tab jake smj ayega
//ki kaise multiple big squares possible hai,aur phir dp ka use karkeaapanswer storkrai
//3 directions ka minimum lene se ye pata lag jayega maximum kitne size ka square bn ra
// 1 0 1 0 0          dp-> 1 0 1 0 0
// 1 0 1 1 1               1 1 1 1 1
// 1 1 1 1 1               1 1 1 2 2(deko teno neighbour2 yani 2 size ka possible,to1to
// 1 0 1 1 1               1 1 1 2 3  maximum 3 size ka square bn sake yaha  
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='1')dp[i][j]=1;
                }else{
                    if(matrix[i][j]=='1'){
                        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                }
                 ans=max(ans,dp[i][j]);
            }
           
        }
        return ans*ans;
    }
};
