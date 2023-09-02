class Solution {
public:
    long dp[5005][2];
    int mod=1e9+7;
    int numOfWays(int n) {
        // dp[i][0] represents current row color with 2 colors
        // dp[i][1] represents current row color with 3 colors
        dp[0][0]=dp[0][1]=6;//intital case
        for(int i=1;i<n;i++){
            // if previous row is colored with 3 colors, if we want the current row colored with 2 colors then there 3 ways
            // if prevrow is colored with2 colors and if we want the current row colored with 3 colors then there are 2 ways
            dp[i][0] =((3*dp[i-1][0])%mod+(2*dp[i-1][1])%mod);
//  if previous row is colored with 3 colors, if we want the current row colored with 3 colors then there 2 ways
//             if prevrow is colored with2 colors and if we want the current row colored with 3 colors then there are 2 ways
            dp[i][1]=((2*dp[i-1][0])%mod+(2*dp[i-1][1])%mod);
        }
  //answer :total cnt of that are colored with 2 colors + toatl cnt of that colore with 3 colors
        return (dp[n-1][0]+dp[n-1][1])%mod;
        
    }
};
   
