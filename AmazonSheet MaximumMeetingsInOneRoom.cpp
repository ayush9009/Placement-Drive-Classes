class Solution{
public:
// simiilar to activity selection problem,sort accoding to finsih time then check start time of this meeting
// is greater than finish time of previous meeting
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
    //   sort() according to finish time
      pair<int,int>p[n+1]; //array of pairs
      for(int i=0;i<n;i++){
          p[i].first=f[i];
          p[i].second=i;
      }
      sort(p,p+n); //sort accoding to finish time
      vector<int>ans;
      ans.push_back(p[0].second+1); //ek meeting to hogi hi hogi
      int maxi=p[0].first;
      for(int i=1;i<n;i++){
          if(s[p[i].second] > maxi){
              ans.push_back(p[i].second+1);
              maxi=p[i].first;
          }
      }
      sort(ans.begin(),ans.end());
      return ans;
       
    }
};
