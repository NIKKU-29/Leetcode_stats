class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        int n = word.size();
        vector<int> seg;
        int i = 0;

        // Compressing the string into segments of consecutive characters
        while (i < n) {
            int count = 0;
            while (i < n - 1 && word[i] == word[i + 1]) {
                count++;
                i++;
            }
            count++;
            seg.push_back(count);
            i++;
        }

        int freq_prod = 1;
        for (auto it : seg) {
            freq_prod = (1LL * freq_prod * it) % MOD;
        }

        if (seg.size() >= k) return freq_prod;

        int totalPossibility = freq_prod;

        // Bottom-up DP: dp[i][len] --> dp[m+1][k+1]
        int m = seg.size();
        // vector<vector<int>> dp(m+1, vector<int> (k + 1, 0));
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);

        // Base Case
        for (int len = 0; len < k; len++) {
            prev[len] = 1;
        }

        // Fill the DP table from m-1 to 0
        for (int idx = m - 1; idx >= 0; idx--) {

            // for (int len = k-1; len >= 0; len--) {
            //     int res = 0;
            //     for (int take = 1; take <= seg[idx]; take++) {
            //         if (len + take < k) {
            //             res = (res + dp[idx+1][len + take]) % MOD;
            //         } else {
            //             break;
            //         }
            //     }
            //     dp[idx][len] = res;
            // }

            // Optimisation: Prefix Sum
            vector<int> prefix(k+1, 0);
            for(int j = 1; j <= k; j++) {
                prefix[j] = (prefix[j-1] + prev[j-1])%MOD;
            }

            for (int len = k-1; len >= 0; len--) {

                int l = len + 1;
                int r = len + seg[idx];

                if(r+1 > k) r = k-1;
                if(l <= r) {
                    curr[len] = (prefix[r+1] - prefix[l] + MOD) % MOD;
                }
            }

            prev = curr;

        }

        int invalids = prev[0];
        int ans = (totalPossibility - invalids + MOD) % MOD;
        return ans;
    }
};