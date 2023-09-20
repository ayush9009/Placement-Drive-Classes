class Solution {
public:
    vector<string>result;
    string Invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')s[i]='0';
            else {
                s[i]='1';
            }
        }
        // cout<<s<<" ";
        return s;
    }
    string Reverse(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    void helper(int n){
        result.push_back("0");
        for(int i=1;i<n;i++){
            string s=result[i-1];
            string invert=Invert(s);
            string revert=Reverse(invert);
            // cout<<s + "1" + revert<<" ";
            result.push_back(s + "1" + revert);
        }
    }
    char findKthBit(int n, int k) {
        helper(n);

        string str=result[n-1];
        // for(auto it:result)cout<<it<<" ";
        // cout<<str;
        return str[k-1];
    }
};
