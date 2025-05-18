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

    bool isValid(string& a, string& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int solver(vector<string>& combinations, int col, int prevIndex, vector<vector<int>>& dp) {
        if (col == n) return 1;
        if (prevIndex != -1 && dp[col][prevIndex] != -1) return dp[col][prevIndex];

        int ans = 0;

        for (int i = 0; i < combinations.size(); i++) {
            if (prevIndex == -1 || isValid(combinations[i], combinations[prevIndex])) {
                ans = (ans + solver(combinations, col + 1, i, dp)) % MOD;
            }
        }

        if (prevIndex != -1) dp[col][prevIndex] = ans;
        return ans;
    }

    int colorTheGrid(int _m, int _n) {
        m = _m;
        n = _n;

        vector<string> combinations;
        string curr = "";
        builder(m, curr, combinations);    

        int k = combinations.size();
        vector<vector<int>> dp(n, vector<int>(k, -1));

        return solver(combinations, 0, -1, dp);
    }
};
