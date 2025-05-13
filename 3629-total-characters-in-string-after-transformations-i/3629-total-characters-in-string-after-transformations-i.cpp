class Solution {
public:
    const int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<long long> next(26, 0);

            for (int i = 0; i < 26; ++i) {
                if (freq[i] == 0) continue;

                if (i == 25) { // 'z'
                    next[0] = (next[0] + freq[i]) % mod;
                    next[1] = (next[1] + freq[i]) % mod;
                } else {
                    next[i + 1] = (next[i + 1] + freq[i]) % mod;
                }
            }

            freq = next;
        }

        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + freq[i]) % mod;
        }

        return total;
    }
};
