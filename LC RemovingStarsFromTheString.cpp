class Solution {
public:
    string removeStars(string s) {
     stack<char>st;
     for(int i=0;i<s.size();i++){
         if(s[i]=='*'){
             if(st.empty()==false ){
                 st.pop();
             }
         }else{
             st.push(s[i]);
         }
     }   
     string str;
     while(!st.empty()){
         str+=st.top();
         st.pop();
     }
     reverse(str.begin(),str.end());
     cout<<str;
     return str;
    }
};
