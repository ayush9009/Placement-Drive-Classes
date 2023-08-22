class Solution {
public:
//first of all remove duplicate element then sort nums(so that we easily get the cont.array,now start from every index one by one so that we consider that part in whcih we get the maximum size of our window,how to increase the size of window ,consider only elements which are less than nums[start]+n (i.e mini+maxi),after this we get maximum size of our window for particular index,now we include in maxi size of window=end -start)and in the end we return n-maxi(our answer)
    int minOperations(vector<int>& nums) {

     int n=nums.size();
        set<int>set;
        for(auto it:nums){
            set.insert(it); //get all the unique elements in nums
        }
        vector<int>v;
        for(auto it:set){
            v.push_back(it);
        }
        sort(v.begin(),v.end());
        int right=0;
        int maxi=INT_MIN;
        int p=v.size();
        for(int left=0;left<n;left++){
           while(right<p&&v[right]-v[left]<=n-1) {
                  //     //    nums[start]+n (current(mini)+ m(maxi)) according to defintion of contin.array
    //     // i.e current + nums[m] i.e nums[start]+m

               //    we consider current element as first element of our continuous array,and we include all the elements in our continous array that are less than nums[start]+n(because this is our range for array)
               right++;
           }
            int cur_count=right-left;
            maxi=max(cur_count,maxi);
        }
        return n-maxi;//n-maxi minimum operations required to make it happen
    }
};
