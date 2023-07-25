class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int ans=0;
        // aabbccdd
        //   * * * ,*denotes particular subequence is visited(taki hum same seq. multiple times na cnt kare)
        //   ******
        while(1){
            int i=0,j=0;
            int flag=0;
            while(i<s.size()){
                if(s[i]==w[j]){
                    j++;
                    s[i]='*';
                }
                if(j==w.size()){
                    ans++;
                    flag=1;
                    break;//break taki koi aur agr seq.ha to vo bhi hum cnt kar sake
                }
                i++;
            }
            if(flag==0)break; //means there is no subsquence
        }
        return ans;
    }
};
