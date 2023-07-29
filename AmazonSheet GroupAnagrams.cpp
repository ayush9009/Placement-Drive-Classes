class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& str) {
        //code here
        unordered_map<string,vector<string>>mp;
        string temp="";
        for(int i=0;i<str.size();i++){
            temp=str[i];
            sort(str[i].begin(),str[i].end());
            // for(auto it:str[i])cout<<it<<" ";
            // cout<<endl;
            mp[str[i]].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
