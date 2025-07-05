class Solution {
public:
    long long recur(int i, int j, bool isEven, vector<vector<int>>& waitCost, int m, int n, vector<vector<vector<long long>>>& dp) {
        if (i >= m || j >= n) return LLONG_MAX;
        if (i == m - 1 && j == n - 1) return 0;
        if (i == 0 && j == 0 && !isEven) {
            long long val1 = LLONG_MAX, val2 = LLONG_MAX;
            if (m > 1) val1 = (2LL * 1) + recur(1, 0, true, waitCost, m, n, dp);
            if (n > 1) val2 = (1LL * 2) + recur(0, 1, true, waitCost, m, n, dp);
            return (1LL * 1) + min(val1, val2);
        }

        if (dp[i][j][isEven] != -1) return dp[i][j][isEven];

        long long cost = 0;
        if (isEven) {
            cost = waitCost[i][j] + recur(i, j, false, waitCost, m, n, dp);
        } else {
            long long val1 = LLONG_MAX, val2 = LLONG_MAX;
            if (i + 1 < m)
                val1 = (1LL * (i + 2) * (j + 1)) + recur(i + 1, j, true, waitCost, m, n, dp);
            if (j + 1 < n)
                val2 = (1LL * (i + 1) * (j + 2)) + recur(i, j + 1, true, waitCost, m, n, dp);
            cost = min(val1, val2);
        }

        return dp[i][j][isEven] = cost;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return recur(0, 0, false, waitCost, m, n, dp);
    }
};
