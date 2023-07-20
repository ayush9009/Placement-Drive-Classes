class Solution{

    public:
    int repeatedStringMatch(string a, string b) 
    {
        // Your code goes here
        int cnt=1;
        string str=a;
        int repeat=b.size()/a.size();
        for(int i=0;i<repeat+2;i++){
            if(a.find(b)!=string::npos)return cnt;
            else{
                a+=str;
                cnt++;
            }
        }
        return -1;
    }
  
};
