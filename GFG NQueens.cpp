class Solution{
public:
vector<vector<int>>result;
    bool isSafe(int row,int col, vector<vector<int>>&board){
        int n=board.size();
        int uprow=row;
        int upcol=col;
        //upper diagonal
        while(col>=0 && row>=0){
            if(board[row][col]==1)return false;
            row--;
            col--;
        }
        //straight diaongal
        col=upcol,row=uprow;
        while(col>=0){
            if(board[row][col]==1)return false;
            col--;
        }
         //lower diaongal
        col=upcol,row=uprow;
        while(col>=0 && row<n){
            if(board[row][col]==1)return false;
            row++;
            col--;
        }
        return true;
    }
    bool helper(vector<vector<int>>&board,int col){
        int n=board.size();
        if(col==n){
            vector<int>v;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==1)v.push_back(j+1);
                }
            }
            result.push_back(v);
            return true;
        }
        bool res=false;
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]=1;
                res=helper(board,col+1) || res; //try all the possible cases
                board[row][col]=0; //backtrack
            }
        }
        return res;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>board(n,vector<int>(n,0));
        if(helper(board,0)==false){
            return {};
        }
        sort(result.begin(),result.end());
        return result;
    }
};
