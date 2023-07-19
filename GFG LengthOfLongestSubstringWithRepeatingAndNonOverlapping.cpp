class Solution {
  public:
    string helper(string s1,string s2){
       int n=s1.size();
       string str="";
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       int maxi=0,ind=0;
       for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
            //   j-i>dp[i-1][j-1] to avoid overlapping
               if(s1[i-1]==s2[j-1] && (j-i)>dp[i-1][j-1]){
               dp[i][j]=1+dp[i-1][j-1];
               if(dp[i][j]>maxi){
                   maxi=dp[i][j];
                   ind=max(ind,i);  //so that manlo ek string milri ind=0 vohi same stirng mili dubare ind=5
                //   to ind=5 vali return kar rai yaha hum
               }
               }
           }
       }
       if(maxi>0){
           for(int i=ind-maxi+1;i<=ind;i++){
               str+=s1[i-1];
           }
       }
       
       return str;
    }
    string longestSubstring(string s, int n) {
        // code here
        string ans=s;

        ans= helper(s,ans);
        if(ans.size()>0)return ans;
        int value = -1;
        string result = to_string(value);
        return result;
    }
};
