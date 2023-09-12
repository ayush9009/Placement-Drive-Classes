class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         if(intervals.size()==0)return ans;
         vector<int>result=intervals[0];
         for(auto it:intervals){
             if(it[0]<=result[1]){
                 result[1]=max(it[1],result[1]);
             }else{
                 ans.push_back(result);
                 result=it;
             }
         }
         if(result.size()>0)ans.push_back(result);
         return ans;
    }
};
