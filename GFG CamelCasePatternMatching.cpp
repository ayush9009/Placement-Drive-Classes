class Solution {
public:
    bool check(string str1, string str2) {
        if (str1 == str2) return true;
        int pos = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[pos]) {
                pos++;
            }
            else if(pos==str2.size())return true;
            else if(str1[i]>='A' && str1[i]<='Z')return false;
            
        }
        return pos == str2.size();
    }
    
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        for (int i = 0; i < Dictionary.size(); i++) {
            if (check(Dictionary[i], Pattern))
                ans.push_back(Dictionary[i]);
        }
        if (ans.empty()) ans.push_back("-1");
        
        return ans;
    }
};
