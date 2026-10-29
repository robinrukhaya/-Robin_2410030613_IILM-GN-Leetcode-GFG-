
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;

        // Mark the numbers that appear
        for (int i = 0; i < n; i++) {
            freq[nums[i]] = 1;
        }

        // Find the missing numbers
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
