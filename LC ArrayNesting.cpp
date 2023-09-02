class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        vector<bool>visited(n);
        


        for(int i=0;i<nums.size();i++){
            int cnt=0;
            while(!visited[i]){
                visited[i]=1;
                cnt++;
                i=nums[i];

            }
            res=max(res,cnt);
        }
        return res;
    }
};
