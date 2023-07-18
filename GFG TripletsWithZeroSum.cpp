class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int nums[], int n)
    { 
        //Your code here
        vector<vector<int>>ans;
        sort(nums,nums+n);
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }
        if(ans.size()==0)return false;
        return true;
    }
};
