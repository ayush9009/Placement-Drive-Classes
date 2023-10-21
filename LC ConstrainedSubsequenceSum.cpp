class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(); 
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0],0});
        int count=0, ans=nums[0];
        for(int i=1; i<n; i++){
            while(1){
                int idx = pq.top().second;
                if(i-idx > k) pq.pop();
                else break;
            }
            nums[i] += max(0, pq.top().first);
            pq.push({nums[i], i});
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
