class Solution {
public:

    int solver(int index, int target, vector<int>& coins,
               vector<vector<int>>& dp) {
        if (index < 0) {
            if (target == 0)
                return 1; // Base case: no coins available
            else
                return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        int no_take = solver(index - 1, target, coins, dp);
        int take = false;
        if (target >= coins[index]) {
            take = solver(index, target - coins[index], coins, dp);
        }
        return dp[index][target] = no_take+ take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solver(n - 1, amount, coins, dp);
        return result;
        
    }
};