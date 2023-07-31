class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
      unordered_map<int,int>mp;
      int cnt=0;
      for(int i=0;i<time.size();i++){
          time[i]=time[i]%60;
          cout<<time[i]<<" ";
      }
      for(int i=0;i<time.size();i++){
        //   time[i]==0 means 60%60==0,therfore time[i]==0 ,means 0 bhi exist kare
          int k=(time[i]==0)?0:60-time[i];
          if(mp.find(k)!=mp.end())cnt+=mp[k];
          mp[time[i]]++;
      }
      return cnt;
    }
    
};
