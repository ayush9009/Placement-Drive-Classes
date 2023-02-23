class Solution {
public:
 vector<int> luckyNumbers (vector<vector<int>>& matrix)
{

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    vector<int> minRow;
    vector<int> maxCol;
    
    // adding all minInRows in a vector
    
    for(int i=0;i<m;i++)
    {
        int mini = matrix[i][0];
        
        for(int j=0;j<n;j++)
        {
            mini = min(mini, matrix[i][j]);
        }
        
        minRow.push_back(mini);
    }
    
    // adding all maxInColumns in a vector
    
    for(int i=0;i<n;i++)
    {
        int maxi = matrix[0][i];
        for(int j=0;j<m;j++)
        {
            maxi = max(maxi, matrix[j][i]);
        }
        
        maxCol.push_back(maxi);
    }
    
    // matching if any value is common b/w above 2 vectors
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(minRow[i]==maxCol[j])
            {
                ans.push_back(minRow[i]);
            }
        }
    }
    
    return ans;
}
};
