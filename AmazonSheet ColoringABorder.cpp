class Solution {
public:
// //Intution:two nodes are adjacent if they have same color,
// hume color kise karna,kise nahi ?? agr kisi node ka color 1 hai aur uski charo adjacent direction mai nodes ka color bhi 1 to hum color nahi karengee,else hum color karenge ,hum visited ki jagah negative kar denge value that denotes that ye node sahi hai ise ke components ko aap color kar sako means:
//  if(cnt==4) to hum color ni kar sakte aur is node ko univisted kar do
//  i.e postive bna do isliye arr[row][col]=abs(arr[row][col]); 
//  akri mai loop chlao if arr[i][j]<0 to arr[i][j]=color kar do ,kuki yehi nodes ho sake sirf color jo negagtive humne bnayi hai,
//  One important case ,suppose koi node already visited yani arr[r][c]<0 to iske liye dfs call ni hoga,lakin iska use to ab bhi hoga color check karne mai
//  suppose there is node on arr[0][0],iska color=1,
//  to iski adj arr[0][1]=-1 hai,to is adjancet kai liye dfs ni chelga ,lakin color to same hai abs(arr[0][1]==arr[0][0]) to cnt++,but 
//  if abs(arr[0][1]!=arr[0][0]) to thode color color karenge isliye continue;
// supppose arr[0][0] adjacents:arr[0][1],arr[1][0],arr[-1][0],arr[0][-1]
// ab manlo arr[1][0] kai liye dfs call chl ra aur iski 4 directions mai checking ho ra,to ek direction hai iski arr[0][0] to iske liye dfs call ni chelga lakin agr arr[0][0]==arr[1][0] to arr[1][0]kai lie cnt++ to hoyegi 



    int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>& grid, int row, int col, int clr){
        int n=grid.size();
        int m=grid[0].size();
        grid[row][col]=-grid[row][col];
        int cnt=0;
        for(int i=0;i<4;i++){  //check in every 4 directions
          int r=row+dir[i][0];
          int c=col+dir[i][1];
        //    abs(arr[r][c]!=clr) //means agr visited bhi h to hum us node ka liye dfs call ni karenge but uske color to check karegne kuki agr color same to cnt++ karni pdegi
          if(r<0||c<0||r>=n||c>=m || abs(grid[r][c])!=clr)continue;
          cnt++;
          //agr not visited yani agr arr[r][c]>=0 to hi dfs call hoga
          if(grid[r][c]>=0)dfs(grid,r,c,clr);
        //   arr[r][c]=clr;
        }
        //after we for loop we traverse/cover all directions of arr[row][col]now if cnt==4 means every adjacent of this arr[row][col] have same color(or having same value jo arr[row][col] ki to us direction mai mark that node postive,means not include in the answer )
        if(cnt==4)grid[row][col]=abs(grid[row][col]);
        return;
        //pahle negatvie kar rai thai ab postive yani univisited
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // vector<vector<int>>ans;
        //hume node de raki jiske connected components  ko hume color karna
        dfs(grid,row,col,grid[row][col]);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0)grid[i][j]=color;
            }
        }
        return grid;
    }
};
