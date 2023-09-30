class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1)q.push({i,j});
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            //for row
            for(int i=0;i<n;i++){
                mat[x][i] = 1;
            }
            
            //for col
            for(int i=0;i<m;i++){
                mat[i][y] = 1;
            }
        }
    }
};
