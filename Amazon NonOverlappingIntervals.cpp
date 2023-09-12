class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        
        
        sort(intervals.begin(),intervals.end(),[] (const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];  //1,2 2,3 3,4 1,3  
                            //   0 1 0 1 0 1 0 1 ,so 1,2 and 1,3 deko 2<3 to pahle 1,2 ayega 
        });
        int cur=0;
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            (intervals[i][0]<intervals[cur][1])?cnt++:cur=i;
            
        }
        return cnt;
        
    }
};
