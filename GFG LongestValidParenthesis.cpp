class Solution{
public:
    int maxLength(string s){
       
        int len=0,maxi=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                st.pop();
                if(st.empty())         ///eg:((()))) to is case mai empty huha to st.push(6) aur 6-6=0
                st.push(i);                                           //kuki ye valid parenthesis ni h
                len=i-st.top();
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};
