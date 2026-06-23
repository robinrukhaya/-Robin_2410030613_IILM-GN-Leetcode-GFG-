class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n  = prices.size();
        if (n <= 1) return 0;

        int cash = 0;
        int hold = -prices[0];

        for(int i  = 1;i < n;i++) {
            int new_cash = max(cash,hold+prices[i]-fee);
            int new_hold = max(hold, cash-prices[i]);

            cash = new_cash;
            hold = new_hold;
        }
        return cash;
    }
};