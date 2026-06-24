class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n,-1);

        function<int(int)> solve = [&](int i ) {
            if (dp[i] != -1) return dp[i];

            int max_len = 1;

            for (int j = 0;j <i;j++) {
                if (nums[j] < nums[i]) {
                    max_len = max(max_len,1+solve(j));
                }
            }
            return dp[i] = max_len;
        };

        int result = 0;
        for (int i = 0;i <n;i++) {
            result = max(result,solve(i));

        }
        return result;
        
    }
};