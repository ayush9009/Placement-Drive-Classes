class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans;
         map<int,set<int>>mp;
        for(auto it:logs){
            mp[it[0]].insert(it[1]);
        }
        unordered_map<int,int>mp1;
        for(auto it:mp){
            mp1[it.second.size()]++;
        }
        vector<int>result(k,0);
        for(int i=1;i<=k ;i++){
            if(mp1.find(i)!=mp1.end())
            result[i-1]=(mp1[i]);
        }
        return result;
    }
};
