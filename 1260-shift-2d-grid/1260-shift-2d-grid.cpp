class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m*n;

        k = k%total;

        vector<vector<int>> result(m,vector<int>(n));

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                int idx = i*n+j;
                int newIdx = (idx+k)%total;

                int newRow = newIdx/n;
                int newCol = newIdx%n;
                result[newRow][newCol] = grid[i][j];
            }
        }
        return result;
    }
};