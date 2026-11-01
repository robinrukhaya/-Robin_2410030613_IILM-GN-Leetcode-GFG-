class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < m;i++){
            int minRow = INT_MAX;
            int minCol = 0;

            for(int j = 0;j < n;j++){
                if(matrix[i][j] < minRow){
                    minRow = matrix[i][j];
                    minCol = j;
                }
            }
            bool isMax = true;

            for(int k = 0;k <m;k++){
                if(matrix[k][minCol]> minRow){
                    isMax = false;
                    break;
                }
            }
            if(isMax){
                ans.push_back(minRow);
            }

             
        }
        return ans;
    }
};