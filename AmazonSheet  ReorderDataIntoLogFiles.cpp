class Solution {
public:
   bool static comp(string a,string b){
    //    (' ')+1 iska matlb identifier ki jaha bhi identifier dikhe use s1 m dal do bs
       string s1=a.substr(a.find(' ')+1);
    //    a.substr(a.find(' ')+1) //iska mtlb ye hai first space kai bad jo bhi hai vo s1 m store kar do 
    //    for example:
    //    a="let1 art can" 
    // to s1="art can" kuki first space kai bad art to yaha se agey ki retun hojagi
       string s2=b.substr(b.find(' ')+1);
       if(s1==s2) return a<b;  //means yaha compare hoga shuru ka scene like g1,a8
       else return s1<s2;  // ya compare hore s1="art can" and s2-"art zoo" here s1<s2 
   }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>result,ans;
        for(auto it:logs){
             if(it[it.size()-1]-'0' >=0 && it[it.size()-1]-'0' <=9)ans.push_back(it);
             else result.push_back(it);
        }
        sort(result.begin(),result.end(),comp);
        for(auto it:ans){
            result.push_back(it);
        }
        return result;
    }
};
