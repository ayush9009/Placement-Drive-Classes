// class Solution {
// public:
  
//     vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k){
//     int n=grid.size();
//     int m=grid[0].size();
//     int startRow=0;
//     int startCol=0;
//     int endRow=n-1;
//     int endCol=m-1;
//     // vector<int>result;
//     while(startRow<endRow && startCol<endCol && k--){
//         //right
//         vector<int>result;
//         for(int j=startCol;j<=endCol;j++){
//             result.push_back(grid[startRow][j]);
//         }
//         //down
//          for(int i=startRow+1;i<=endRow;i++){
//             result.push_back(grid[i][endCol]);
//         }
//         //left
//          for(int j=endCol-1;j>=startCol;j--){
//             result.push_back(grid[endRow][j]);
//         }
//         //up
//          for(int i=endRow-1;i>=startRow+1;i--){
//             result.push_back(grid[i][startCol]);
//         }

//         // helper(result);
//         int ind=0;
//         for(int j=startCol;j<=endCol;j++){
//             grid[startRow][j]=result[(ind+k)%result.size()];
//                ind++;
//         }
//         //down
//          for(int i=startRow+1;i<=endRow;i++){
//             grid[i][endCol]=result[(ind+k)%result.size()];
//                ind++;
//         }
//         //left
//          for(int j=endCol-1;j>=startCol;j--){
//               grid[endRow][j]=result[(ind+k)%result.size()];
//                ind++;
//         }
//         //up
//          for(int i=endRow-1;i>=startRow+1;i--){
//               grid[i][startCol]=result[(ind+k)%result.size()];
//                ind++;
//         }

//         startRow++;
//         endRow--;
//         startCol++;
//         endCol--;
//     }
//     return grid;
//     }
// };
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        int startRow=0;
        int startCol=0;
        int endRow=n-1;
        int endCol=m-1;
        while(startRow<endRow && startCol<endCol)
        {
            vector<int>temp;
            //right
            for (int j=startCol;j<=endCol;j++)
            {
                temp.push_back(grid[startRow][j]);
            }
            //down
            for (int i=startRow+1;i<=endRow;i++)
            {
                temp.push_back(grid[i][endCol]);
            }
            //left
            for (int j=endCol-1;j>=startCol;j--)
            {
                temp.push_back(grid[endRow][j]);
            }
            //up
            for (int i=endRow-1;i>=startRow+1;i--)
            {
               temp.push_back(grid[i][startCol]);
            }

            //pushing rotated values in grid
           int ind=0;
            for (int j=startCol;j<=endCol;j++)
            {
               grid[startRow][j]=temp[(ind+k)%temp.size()];
               ind++;
            }
            //down
            for (int i=startRow+1;i<=endRow;i++)
            {
                grid[i][endCol]=temp[(ind+k)%temp.size()];
               ind++;
            }
            //left
            for (int j=endCol-1;j>=startCol;j--)
            {
                grid[endRow][j]=temp[(ind+k)%temp.size()];
               ind++;
            }
            //up
            for (int i=endRow-1;i>=startRow+1;i--)
            {
                grid[i][startCol]=temp[(ind+k)%temp.size()];
               ind++;
            }


            for(auto it:temp){
                cout<<it<<" ";
            }
            cout<<endl;

            startRow++;
            startCol++;
            endRow--;
            endCol--;

        }
        return grid;

    }
};
