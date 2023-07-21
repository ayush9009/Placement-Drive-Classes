class Solution{
  public:
    /*You are required to complete this method */
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int atoi(string s) {
        //Your code here
        int len=s.size();
       if(len==0)return 0;
       int i=0;
       while(i<len && s[i]==' '){
           i++;
       }
       bool isNeg=0;  //if 1 means number is -ve , or if 0 means postivie
       if(i<len){
            if(s[i]=='-'){
              i++;
              isNeg=1; //reprsenting negative
            }else if(s[i]=='+'){
                i++;
            }
       }
       int ans=0;
       while(i<len && isDigit(s[i])){
        
           int dig=s[i]-'0';

           if(ans > (INT_MAX/10) || (ans==INT_MAX/10 && dig >7)){
               return isNeg?INT_MIN:INT_MAX;
           }
           ans=(ans*10) + dig;  
        //    123,  0*10+1=1     1*10+2=12     12*10+3=123

           i++;
       }
       return (isNeg)?(-ans):ans;
     
    }
};
