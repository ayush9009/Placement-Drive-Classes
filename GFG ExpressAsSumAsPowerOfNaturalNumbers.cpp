class Solution {
public:
    const long long mod = 1e9 + 7;

    long long helper(int n, int x, long long i, long long sum, vector<vector<long long>>& dp) {
        if (n == sum) return 1;
        if (n < sum || i > n) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];

        return dp[i][sum]  = (helper(n, x, i + 1, sum + pow(i, x), dp) + helper(n, x, i + 1, sum, dp) + mod) % mod;
        // return dp[i][sum] = ways;
    }

    int numOfWays(int n, int x) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return (helper(n, x, 1, 0, dp));
    }
};
