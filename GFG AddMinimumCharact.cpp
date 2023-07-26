class Solution{   
public:
     int lps(string str){
       int len=0,i=1;
       int n=str.size();
       int lps[n];
        lps[0]=0;
       while(i<n){
           if(str[i]==str[len]){
               len++;
               lps[i]=len;
               i++;
           }else{
               if(len==0){
                   lps[i]=0;
                   i++;
               }else{
                   len=lps[len-1];
               }
           }
       }
       return lps[n-1];
    }
    int addMinChar(string str){    
        //code here
        int n=str.size();
        string ans=str;
        reverse(str.begin(),str.end());
        string concat=ans+ '$' +str;
        return n-lps(concat);
    }
};
