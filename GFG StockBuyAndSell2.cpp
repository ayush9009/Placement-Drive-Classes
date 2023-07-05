class Solution {
  public:
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long profit=0;
        if(buy){
            //if u buy something to aapke paise kuch gye islye -prices[i] aur ind+1 ki next prod buy karogey
            profit=max(-prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp)); 
        }else{
            //agr sell kara to prics[i]profit aur ind+1 
            //ya do hi condition buy aur sell either u buy it or not
            profit=max(prices[ind]+f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};
