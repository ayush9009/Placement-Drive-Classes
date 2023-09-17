class Solution {
public:
    // cur, bit, steps.
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int maxStep = n * (n - 1) / 2;
        vector<vector<int> > dp(n, vector<int>(4200, 1000));
        
        queue<vector<int> > q;
        int bit = pow(2, n) - 1;
        for(int i=0; i<n; ++i) {
            q.push({i, bit - (1 << i), 0});
        }
        
        while(!q.empty()) {
            auto v = q.front(); 
            q.pop();
            
            if(v[1] == 0) return v[2];
            
            if(v[2] > maxStep) continue;
            if(dp[v[0]][v[1]] <= v[2]) continue;
            dp[v[0]][v[1]] = v[2];
            
            for(auto& nxt: graph[v[0]]) {
                int rem = v[1] & (1 << nxt) ? v[1] - (1 << nxt) : v[1];
                q.push({nxt, rem, v[2] + 1});
            }
        }
        
        return -1;
    }
};
