class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Step 1: Flatten
        for (auto &row : grid) {
            for (auto &num : row) {
                arr.push_back(num);
            }
        }
        
        // Step 2: Check feasibility
        int rem = arr[0] % x;
        for (int num : arr) {
            if (num % x != rem) return -1;
        }
        
        // Step 3: Sort
        sort(arr.begin(), arr.end());
        
        // Step 4: Median
        int median = arr[arr.size() / 2];
        
        // Step 5: Count operations
        int operations = 0;
        for (int num : arr) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};