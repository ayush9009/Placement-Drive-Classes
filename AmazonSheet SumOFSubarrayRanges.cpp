class Solution {
public:
// Bahtreen Question
// Approach:supppose quetion is find sum of min element of all subarrays
// means jitni bhi subarays unka minimum leke add karo aur hume dedo
//  to humne ise solve kara tha,ye soch kai ki find the participation of indiviual elements and then sum it
//  for example 2 9 7 8 3 6 4 1 
//              0 1 2 3 4 5 6 7
//              i       j     k
// suppose we need to find for 3,
// so what we do ,we find the left window in 3 is min, j-i
// we find right window in whihc 3 is min,  k-j
// beacase (j-i)*(j-k)are the subarays in which 3 in minium,to hume itni bar 3 add karna padeaga
// i.e 3*(j-i)(k-j) //that's how we find particpation of 3
// this for sum of minimum of all subarrays
// in the same manner we can find sum of maximum of all subarrays
// so our question here is har subarray mai maxi-min nikalke add kardo aur as result dedo
// so heere we can use above same apporcah

// 3* ((maxSum(3)) -minSum(3))
// maxSum upr vali technique se
// minSum upr vali technique se 
// after that multiply by 3,
// differnec between above and this quetion in above we find sum of mini elem of subarrays
// and here we find sum of(maxi-mini of all subarrays)

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        stack<int>st;
        vector<int>minPrev(n,-1),minNext(n,n),maxPrev(n,-1),maxNext(n,n);
        // in stack we store indices instead of elemtns
        // minPrev
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(!st.empty())minPrev[i]=st.top();
            st.push(i);
        }
        // minNext
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i])st.pop();
            if(!st.empty())minNext[i]=st.top();
            st.push(i);
        }
        // maxPrev
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(!st.empty())maxPrev[i]=st.top();
            st.push(i);
        }
        // maxNext
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            if(!st.empty())maxNext[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            // leftmin ,all the subarrays in whcih in nums[i] is minimum
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i; //similarto(j-i)*(k-j)
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i; 

// rightMax*leftMax*nums[i]  sum of all subarrays in which nums[i]is maximum
//  partication of nums[i]=((rightMax*leftMax)-(leftMin*rightMin))*nums[i];
            ans+=((leftMax*rightMax)-(leftMin*rightMin))*nums[i];
        }
        return ans;
    }
};
