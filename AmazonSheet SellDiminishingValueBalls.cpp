#define mod 1000000007
class Solution {
public:
// Mushkkil Saval,Baki jo apporaches hai,like heap,brute force un sab mai tle ajaga
//isliye ye apporach (Need Revision )
    int maxProfit(vector<int>&v, int o) {
        int n=v.size();
        long long ret=0;
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            long long diff=v[i]-(i>0?v[i-1]:0);  //differennce of largest and second largest
            long long x=min((long long)o,(n-i)*diff);
            long long r=v[i];
            long long l=r-x/(n-i);
            ret+=(r*(r+1)/2-l*(l+1)/2)*(n-i);
            ret%=mod;
            ret+=l*(x%(n-i));
            ret%=mod;
            o-=x;
        }
        return ret;
    }
};
