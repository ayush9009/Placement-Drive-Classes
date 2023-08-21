class Solution {
public:
//Here you havev to think more and more,basically u hvae to divide the problem into smaller and 
// smaller part,so that u understand and then apply property of sorted order,whenever there is gap
// between current element and next element we update current element and increment the cnt of patches requried(but we canot add any random number,we have to add minimum number that extend our coverage)
// sum+=sum+1,doubling apporach(means you cover all the sums that u had + new number(sum+1))
    int minPatches(vector<int>& nums, int n) {
        int i=0,cnt=0,tora=0;
        long long sum=0;
        while(  sum<n){
            if(i<nums.size() && nums[i]<=sum+1){
                sum+=nums[i++];
            }else{
                cnt++;

                sum+=sum+1;
                // cout<<sum<<" ";
            }
           tora++;
        }
        cout<<tora;
        return cnt;
    }
};  
