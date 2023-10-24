// Back-end complete function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        
         /* Create two arrays to build the solution in bottom up manner
           C[i] = Minimum number of cuts needed for palindrome partitioning
                     of substring str[0..i]
           P[i][j] = true if substring str[i..j] is palindrome, else false
           Note that C[i] is 0 if P[0][i] is true */
        int C[n];
        bool P[n][n];
        
        int i, j, k, L;
        for(i = 0;i < n;i++)
            P[i][i] = true;
        
        for(L = 2; L <= n;L++){
            for(i = 0;i < n-L+1;i++){
                j = i+L-1;   // set ending index
                
                // If L is 2, then we just need to compare two characters. Else
                // need to check two corner characters and value of P[i+1][j-1]
                if(L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = ((str[i] == str[j]) & P[i+1][j-1]);
            } 
        }
        
        for(i = 0;i < n;i++){
            if(P[0][i])
                C[i] = 0;
            else{
                C[i] = INT_MAX;
                for(j = 0;j < i;j++){
                    if(P[j+1][i] == true & C[j]+1 < C[i])
                        C[i] = C[j]+1;
                }
            }
        }
        return C[n-1];
    }
};
