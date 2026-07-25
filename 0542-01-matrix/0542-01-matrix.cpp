class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;
        
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i  =0; i <n;i++){
            for(int j= 0;j <m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i =0; i < 4;i++){
                int newRow = row+dr[i];
                int newCol = col+dc[i];
            
                if(newRow >=0 && newRow < n && newCol >=0 && newCol < m &&dist[newRow][newCol] == -1){
                    dist[newRow][newCol] = dist[row][col]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return dist;
    }
};