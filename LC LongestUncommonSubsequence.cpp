class Solution {
public:
// approach ye deklo do string mai koi common sequence mil ra kya agr h ,to ye dono string humare answer mai include ni ho sakti accoding to question
//if there is no common sequence to hum include kar sake ise
    bool isSubseq(string x,string y){
        int n=x.size();
        int m=y.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<x<<" "<<y<<" "<<dp[n][m];
        int t=dp[n][m]==n;
        cout<<" "<<t<<endl;
        // return cout<<dp[n][m]==n;
        return (dp[n][m]==n);
    }
    int findLUSlength(vector<string>& str) {
        int ans=-1;
        for(int i=0;i<str.size();i++){
            bool flag=true;
            for(int j=0;j<str.size();j++){
                if(i!=j && isSubseq(str[i],str[j])){
                    flag=false;
                    break;
                }
            }
            if(flag)ans=max(ans,(int)str[i].size());
        }
        return ans;
    }
};
