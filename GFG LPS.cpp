class Solution{
  public:
    int helper(string s1,string s2){
        int n=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
    int longestPalinSubseq(string a) {
        //code here
        int n=a.size();
        string str=a;
        reverse(a.begin(),a.end());
        int ans=helper(str,a);
        return ans;
    }
};
