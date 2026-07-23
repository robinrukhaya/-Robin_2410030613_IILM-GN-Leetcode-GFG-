class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int fresh = 0;

        queue<pair<int, pair<int,int>>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
                if(grid[i][j] == 1){
                    fresh++;
                   
                }
            }
        }
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int time = node.first;
            int row =  node.second.first;
            int col =  node.second.second;

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            for(int i = 0;i <4;i++){
                int newRow = row+dr[i];
                int newCol = col+dc[i];

                if(newRow >=0  && newRow <n && newCol >= 0 && newCol <m && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({time+1,{newRow,newCol}});
                }
            }
            ans= max(ans,time);
            
        }
        
        if(fresh >0){
            return -1;
        }
        return ans;
    }
};