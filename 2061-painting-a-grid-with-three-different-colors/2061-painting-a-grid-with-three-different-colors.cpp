class Solution {
public:
    vector<char> colors = {'R', 'G', 'B'};
    int m, n;
    int MOD = 1e9 + 7;

    void builder(int m, string& curr, vector<string>& combinations) {
        if (curr.size() == m) {
            combinations.push_back(curr);
            return;
        }

        for (char c : colors) {
            if (!curr.empty() && c == curr.back()) continue;
            curr.push_back(c);
            builder(m, curr, combinations);
            curr.pop_back();
        }
    }

    

    int solve(int remainCols, int prevIdx, int m, vector<string>& combinations, vector<vector<int>>& dp) {
    if (remainCols == 0) return 1;
    if (dp[remainCols][prevIdx] != -1) return dp[remainCols][prevIdx];

    int ways = 0;
    string prevState = combinations[prevIdx];

    for (int i = 0; i < combinations.size(); i++) {
        if (i == prevIdx) continue;

        string currState = combinations[i];
        bool valid = true;

        for (int j = 0; j < m; j++) {
            if (prevState[j] == currState[j]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ways = (ways + solve(remainCols - 1, i, m, combinations, dp)) % MOD;
        }
    }

    return dp[remainCols][prevIdx] = ways;
}


    int colorTheGrid(int _m, int _n) {
        m = _m;
        n = _n;

        vector<string> combinations;
        string curr = "";
        builder(m, curr, combinations);    

        int k = combinations.size();
        vector<vector<int>> dp(n, vector<int>(k, -1));

         int ans = 0;

        for (int i = 0; i < combinations.size(); i++) {
            ans = (ans + solve(n - 1, i, m, combinations, dp)) % MOD;
        }

        return ans;
    }
};
