class Solution {
public:
//VVIP QUESTION ON BINARY SEARCH


    int sliding(vector<int>&nums,int diff ,int n){
        //in this function we count how many  have abosilute difference less than or equal to diff
        // 1,2,5,10 we take j=0 i=1 intially mid=5 
        // 1-2<=5 i increment hora  cnt=i-j i.e cnt=1-0=1
        // 1-5<=5  i increment hora cnt=i-j i.e cnt=2-0=2
        // 1-10!<=5 so now we move pointer from 1 to 2 ,means in this case j increment hora
        int  cnt=0,j=0;
        for(int i=1;i<nums.size();i++){
            // if(nums[i]-nums[j]<=diff)cnt+=i-j;
            while(nums[i]-nums[j]>diff)j++;  //jab tak ye scene to j incremnt kar do
            cnt+=i-j; //jaise hi j sahi huha humne count note karli
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort( nums.begin(),nums.end());
       
       int low =INT_MAX;     //miinimum possible absoulte difference
       for(int i=1;i<nums.size();i++){
           low=min(low,nums[i]-nums[i-1]);
       }
       int n=nums.size();
       int high=nums[n-1]-nums[0]; //maximum possible absoulte difference
       while(low<high){
           int mid=(low+high)/2;
        //    using sliding we try to find how many have difference less than or equal to k
           int ans=sliding(nums,mid,n);  //if cnt of pairs <k means this is not inlcude in our answer
        //    suppose 1,2,5,10  k=5 suppose for mid=5 we get 4 and we want 5th smallest element so mid=5 
        //    is not our case ,and all the elements in left side of 5 canot give answer,to we have to update our range i.e low =mid+1
        //    but suppose k=5 and mid=8 now high =mid that's how we shrink the range,in the end one time come when low =high at this time we return low becuase this is our answer'
           if(ans<k)low=mid+1;
           else high=mid;
       }
       return low; //jab low=high ho jayenge
    }
};
