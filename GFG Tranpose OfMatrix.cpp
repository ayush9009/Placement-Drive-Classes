class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        int row=matrix.size();
        int  column=matrix[0].size();
        vector<vector<int>>result(column,vector<int>(row,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++)
            {
                result[i][j]=matrix[i][j];
            }

        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++)
            {
                matrix[j][i]=result[i][j];
            }

        }
        //  return result;
    }
};
