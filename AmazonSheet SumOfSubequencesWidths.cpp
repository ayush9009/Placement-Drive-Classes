class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
      
    //    see,since we have to find the subsequences for differnce of max and min
    //    so we sort the nums there is no problme in it,and check for particpation of each individal element of nums,

    //    2^i these are the subseq in which nums[i] is maximum
    //    2^(n-i-1) these are the subseq in which nums[i] is minimum

    //    particaitpion of nums[i]=upper-lower=nums[i]*2^i -nums[i]*2^(n-i-1);

    //    now see,this is for one element ,if there is large series,so we have to so many calucation

    // like ans=sum{nums[i]*2^i -nums[i]*2^(n-i-1)+.....},
    // bascially ye ,har element kai liye karna padega,nums[i]*2^i -nums[i]*2^(n-i-1) ,
    // so on solving above series,we taking 2^i common so we get below expresiion:
    // 2*i{nums[i]-nums[n-i-1]}
    // so ans+=2*i{nums[i]-nums[n-i-1]} this is the particpatino of every element

    //    2^i,2^(n-i-1) ye cheez pata chlege jab aap qestion try karogey
    //    har element kai liye,dekohey ki ,kitne subsequ mai ye min,aur kitne mai max

    //    2^i precalculate karlo nahi to baar calucate mai dikt degi
       int n=nums.size();
       long mod=1e9+7;
       sort(nums.begin(),nums.end());
       int ans=0;
       vector<long>exp(n,0);
       exp[0]=1;
       for(int i=1;i<n;i++)exp[i]=exp[i-1]*2%mod;
       for(int i=0;i<nums.size();i++){
           ans=(ans+exp[i]*(nums[i]-nums[n-i-1]))%mod; // 2^i*{upper-lower} i.e 
        //    2^i*{nums[i]-nums[n-i-1]} 
       }
       return ans%mod;
    }
};
