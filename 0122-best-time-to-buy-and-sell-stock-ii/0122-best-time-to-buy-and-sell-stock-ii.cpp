class Solution {
public:
    int solver(int idx, int mode, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx == prices.size()) return 0;

        if (dp[idx][mode] != -1) return dp[idx][mode];

        int profit = 0;
        if (mode == 0) {
            int take = -prices[idx] + solver(idx + 1, 1, prices, dp);
            int notake = solver(idx + 1, 0, prices, dp);
            profit = max(take, notake);
        } else {
            int sell = prices[idx] + solver(idx + 1, 0, prices, dp);
            int notsell = solver(idx + 1, 1, prices, dp);
            profit = max(sell, notsell);
        }

        return dp[idx][mode] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Memoization table
        return solver(0, 0, prices, dp);
    }
};
