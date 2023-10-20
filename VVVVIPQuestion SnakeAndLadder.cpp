class Solution{
public:
    int minThrow(int N, int arr[]){
        // code hereof
       int moves[35];
        bool vis[35];
        memset(moves, -1, sizeof(moves));
        memset(vis, false, sizeof(vis));
        
        // Store the moves in the moves array
        for(int i = 0;i < 2*N;i += 2)
            moves[arr[i]] = arr[i+1];
        
        // Use BFS to find the minimum number of moves
        queue<pair<int, int>> q;
        pair<int, int> p;
        q.push({1, 0}); // Start from position 1 with 0 moves
        vis[1] = true;
        
        // Perform BFS
        while(!q.empty()){
            p = q.front();
            int ii = p.first;
            int ss = p.second;
            
            // If destination is reached, break the loop
            if(ii == 30)
                break;
            
            q.pop();
            
            // Generate all possible moves from current position
            for(int i = ii+1;i <= ii+6 && i <= 30;i++){
                pair<int,int> pp;
                
                // Check if the move has been visited
                if(!vis[i]){
                    pp.second = ss+1; // Increment the number of moves
                    vis[i] = true;
                    
                    // Check if the move leads to any ladder or snake
                    if(moves[i] != -1)
                        pp.first = moves[i];
                    else
                        pp.first = i;
                    
                    // Add the move to the queue
                    q.push(pp);
                }
            }
        }
        
        // Return the minimum number of moves required to reach the destination
        return p.second;
    }
};
