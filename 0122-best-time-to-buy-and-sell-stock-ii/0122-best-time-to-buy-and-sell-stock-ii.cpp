// class Solution {
// public:
//     int solver(int idx, int mode, vector<int>& prices, vector<vector<int>>& dp) {
//         if (idx == prices.size()) return 0;

//         if (dp[idx][mode] != -1) return dp[idx][mode];

//         int profit = 0;
//         if (mode == 0) {
//             int take = -prices[idx] + solver(idx + 1, 1, prices, dp);
//             int notake = solver(idx + 1, 0, prices, dp);
//             profit = max(take, notake);
//         } else {
//             int sell = prices[idx] + solver(idx + 1, 0, prices, dp);
//             int notsell = solver(idx + 1, 1, prices, dp);
//             profit = max(sell, notsell);
//         }

//         return dp[idx][mode] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1)); 
//         return solver(0, 0, prices, dp);
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
        
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] > prices[i - 1]) {
//                 profit += prices[i] - prices[i - 1];
//                 cout<<i<<"_"<<profit<<"'";
//             }
//         }
        
//         return profit;        
//     }
// };


class Solution {
public:



    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0)); 

        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int idx = n-1 ; idx >= 0 ; idx--)
        {
            for(int mode = 0 ; mode <= 1 ; mode++)
            {
               int profit = 0;
                if (mode == 0) {
                    int take = -prices[idx] + dp[idx+1][1];
                    int notake = dp[idx+1][0];
                    profit = max(take, notake);
                } else {
                    int sell = prices[idx] + dp[idx+1][0];
                    int notsell = dp[idx+1][1];
                    profit = max(sell, notsell);
                }


                dp[idx][mode] = profit;

            }
        }

        return dp[0][0];

   }
};