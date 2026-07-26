class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n-1] * nums[n-2] * nums[n-3];       // three largest
        int b = nums[0] * nums[1] * nums[n-1];           // two smallest (possibly negative) * largest
        return max(a, b);
    }
};