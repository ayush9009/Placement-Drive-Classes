class Solution {
public:
    // vector<vector<int>> perm(vector<int> nums)
    // {
        // if(nums.size()==0)
        // {
        //     return {{}};
        // }
        //  vector<vector<int>> ans;
        // for(int i=0;i<nums.size();i++)
        // {
        //   vector<int>nums2;
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if(i!=j)
        //         {
        //             nums2.push_back(nums[j]);
        //         }
        //     }
        //      vector<vector<int>> v=perm(nums2);
        //     for(auto a:v)
        //     {
        //         a.push_back(nums[i]);
        //         ans.push_back(a);
        //     }
        // }
        // return ans;
    // }
    void func(int index,vector<vector<int>>&ans,vector<int>&nums){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            func(index+1,ans,nums);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // return perm(nums);
        vector<vector<int>>ans;
        func(0,ans,nums);
        return ans;
    }
};
