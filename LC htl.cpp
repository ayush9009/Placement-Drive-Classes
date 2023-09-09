class Solution {
public:
    int dfs(vector<int>& nums, int t,vector<int>& dp){
        if(t<0)return 0;          //agr number target -ve  to koi psoiblity ni ki uska combinaion bn jaye isliye 0
        if(dp[t]!=-1)return dp[t];
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x+dfs(nums,t-nums[i],dp);
        }
        dp[t]=x;
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        dp[0]=1;     //ek coount to possible hai hi chae koi bhi number ho
        return dfs(nums,target,dp);
    }
};
