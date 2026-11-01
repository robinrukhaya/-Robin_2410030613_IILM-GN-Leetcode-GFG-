class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0;
        int front = 0;
        int side = 0;
        for(int i =0;i < grid.size();i++){
            for(int j= 0;j < grid[0].size();j++){
                if(grid[i][j] > 0){
                    top++;
                }
            }
        }
        for(int i =0;i < grid.size();i++){
            int maxRow =0;
            for(int j = 0; j < grid[0].size();j++){
                maxRow = max(maxRow,grid[i][j]);
            }
            front+= maxRow;
        }
        for(int j = 0; j < grid[0].size();j++){
            int maxCol = 0;
            for(int i = 0; i < grid.size();i++){
                maxCol = max(maxCol,grid[i][j]);
            }
            side += maxCol;
        }
        return top+front+side;
        
    }
};