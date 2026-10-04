class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> ans;

    for (int i = 0; i < rows; i++) {

        int minValue = INT_MAX;
        int minColumn = -1;

        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minColumn = j;
            }
        }

        bool isLucky = true;

        for (int k = 0; k < rows; k++) {

            if (matrix[k][minColumn] > minValue) {
                isLucky = false;
                break;
            }
        }

        if (isLucky) {
            ans.push_back(minValue);
        }
    }

    return ans;
}
};