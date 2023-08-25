class Solution {
public:
    int calculate(string s) {
        s+='+';  //ye isliye kiya suppose 3+2*4 to according to our logic
        // cur=2 sign='+' now s[i]='+' sign ='+' st.push(+3) and sign='+' cur=0
        // cur=2 ,s[i]='*' but sign='+' st.push(+2) sign='*' cur=0 
        // now cur=4 ,to iske hisasb se st mai sirf 3,2 hai jabki 4 bhi hona chaiye
        // isliye3+2*4+ kiya
        // now cur=4 but s[i]='+' and sign='*' so st.top*cur 2*4=8 st.pop()
        // now stack have : 3,8 therfore 3+8=11 this is required answer

        cout<<s;
         stack<int >st;
         char sign='+';
        long long int cur=0;
         for(int i=0;i<s.size();i++){
             if(isdigit(s[i]))cur=cur*10 + s[i]-'0';
             else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                 if(sign=='+'){
                     st.push(+cur);
                 }else if(sign=='-'){
                     st.push(cur*(-1));
                 }else if(sign=='*'){
                     int num=st.top();st.pop();
                     st.push(cur*num);
                 }else if(sign=='/'){
                     int num=st.top();st.pop();
                     st.push(num/cur);
                 }
                 cur=0;
                 sign=s[i];
             }
         }
         long long int sm=0;
         while(!st.empty()){
             sm+=st.top();
             st.pop();
         }
         return sm;
    }
};
