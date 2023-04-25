class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                }
            }
        }
        int cnt=0;
        int j=y,i=x;
        while(j>=0 && board[i][j]!='B'){
             if(board[i][j]=='p'){
                cnt++;
                break;
            }
            j--;
        }
        i=x,j=y;
        while(i>=0 && board[i][j]!='B'){
            if(board[i][j]=='p'){
                cnt++;
                break;
            }
            i--;
        }
       i=x,j=y;
       while(i<n && board[i][j]!='B'){
            if(board[i][j]=='p'){
                cnt++;
                break
            }
            i++;
       }
        j=y,i=x;
        while(j<m && board[i][j]!='B'){
            if(board[i][j]=='p'){
                cnt++;
                break;
            }
            j++;
        }
        return cnt;
    }
};
