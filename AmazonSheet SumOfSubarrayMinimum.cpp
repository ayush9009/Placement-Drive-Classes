class Solution {
public:
// 2 9 7 8 3 4 6 1
//    0 1 2 3 4 5 6 7 (0 base indexing)
// suppose element is 3 to 3 prevSmaller=2 ,nextSmaller=1
// nextSmaller indeX+1 means these are the elemtns which are greater than 3 in right side
// prevSmaller index+1 means these are the elements ehich are greater than 3 in lefft side

// 1 index=7 
// required answer=element*(prevSmaller indx+1) * (nextSmaller index+1) 

// suppose 3 nextSmaller not exist
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        stack<int>s1,s2;
        vector<int>nextSmaller(n),prevSmaller(n);
        for(int i=0;i<n;i++){
            nextSmaller[i]=n-i-1; //suppose next smaller ha  ni  to 
            // suppose 2 9 7 8 3 4 6
            // to 3 nextsmaller not exits 
            // 7-4-1=2 i.e (4,6) are the elements which r greaterthanpresent in rightof3
            prevSmaller[i]=i;
            //suppose 9 7 8 3 4 6 1 to 3 prev not exist so elemetns=i i.e 3(3 index=3)
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() && a[s1.top()]>a[i]){
                nextSmaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && a[s2.top()]>=a[i]){
                prevSmaller[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        //nextSmaller[i] means no elements greater than i in right side
        //prevSmaller[i] means no elements greater than i in left side
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans=(ans+(a[i]*(long long)(nextSmaller[i]+1)*(prevSmaller[i]+1))%mod)%mod;
        }
        return (int)ans;
    }
};
