class Solution {
public:
//Easiest Sliding Window Solution
    int maximumBeauty(vector<int>& nums, int k) {
       int s=0,mxi=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
           while(s<i && nums[s]+k<nums[i]-k){
               s+=1;
           }
           mxi=max(mxi,i-s+1);
           //i-s+1 denotes window size
       }
       return mxi;
        
    }
};
