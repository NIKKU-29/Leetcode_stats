class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        constexpr int MOD = 1e9 + 7;
        long cnts[26] = {}; // Frequency of each letter a-z

        // Step 1: Count initial characters in the string
        for (char c : s) {
            cnts[c - 'a']++;
        }

        // Step 2: While t >= 26, simulate one full 26-step cycle
        while (t >= 26) {
            long temp[26] = {};

            for (int i = 0; i < 25; ++i) {
                temp[i + 1] += cnts[i];
            }

            temp[0] += cnts[25];  // z → a
            temp[1] += cnts[25];  // z → b

            for (int i = 0; i < 26; ++i) {
                cnts[i] = (cnts[i] + temp[i]) % MOD;
            }

            t -= 26;
        }

        // Step 3: Simulate the remaining t steps one by one
        while (t-- > 0) {
            long temp[26] = {};

            for (int i = 0; i < 25; ++i) {
                temp[i + 1] += cnts[i];
            }

            temp[0] += cnts[25];  // z → a
            temp[1] += cnts[25];  // z → b

            for (int i = 0; i < 26; ++i) {
                cnts[i] = temp[i] % MOD;
            }
        }

        // Final answer: sum of all characters
        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnts[i]) % MOD;
        }

        return (int)ans;
    }
};
