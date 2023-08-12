class Solution {
public:
//use sliding window to count distinct integers,maintain a hashmap also
// but pointers are intialy at 0,whenever u see the size of hasmap greater than k ,update the hashmap and increment the left pointer also.if this is not the case then increment the count accordinly,i.e end-start+1 and end++ to move to window

    int helper(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        int left=0,right=0,count=0;
        while(right<n){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--; //erase the eelement preasent at beigninng
                if(mp[nums[left]]==0){ 
                    mp.erase(nums[left]);
                }
                 left++;//incremnt the left pointer to move the window 
            }
            count+=right-left+1;
            cout<<count<<" ";
            right++;
        }
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {

// tricks part :
// exactly k distinct elements=cntsubaryswithATMOSTK - cntofsubarywithATMOSTK-1

        // cout<<helper(nums,k)<<endl;
        // cout<<helper(nums,k-1);
        return helper(nums,k)-helper(nums,k-1);
    }
};

