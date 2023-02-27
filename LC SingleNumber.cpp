class Solution {
public:
    int singleNumber(vector<int>& nums) {
   // int j=nums[0];
   //      for(int i=0;i<nums.size()-1;i++)
   //      {
   //         j^=nums[i+1];   
   //      }
   //      return j;
   //  }
        // int ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto x:mp){
        //     if(x.second==1)
        //     {
        //         ans=x.first;
        //         break;
        //     }
        // }
        //     return ans;
        // }
        int j=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            j^=nums[i+1];
        }
        return j;
    }
};
