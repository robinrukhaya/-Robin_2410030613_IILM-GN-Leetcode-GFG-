class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int s0 = 0;
        int s1 = -prices[0];
        int s2 = INT_MIN;

        for (int i = 1;i < n;i++) {
            int new_s0 = max(s0 , s2);
            int new_s1 = max(s1,s0-prices[i]);
            int new_s2 = s1+ prices[i];

            s0 = new_s0;
            s1 = new_s1;
            s2 = new_s2;
        }
        return max(s0,s2);
    }
};