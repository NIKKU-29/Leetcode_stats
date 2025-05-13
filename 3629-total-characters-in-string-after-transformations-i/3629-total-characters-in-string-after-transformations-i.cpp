// class Solution {
// public:
//     const int mod = 1e9 + 7;

//     int lengthAfterTransformations(string s, int t) {
//         vector<long long> freq(26, 0);

//         for (char c : s) {
//             freq[c - 'a']++;
//         }

//         for (int step = 0; step < t; ++step) {
//             vector<long long> next(26, 0);

//             for (int i = 0; i < 26; ++i) {
//                 if (freq[i] == 0) continue;

//                 if (i == 25) { 
//                     next[0] = (next[0] + freq[i]) % mod;
//                     next[1] = (next[1] + freq[i]) % mod;
//                 } else {
//                     next[i + 1] = (next[i + 1] + freq[i]) % mod;
//                 }
//             }

//             freq = next;
//         }

//         long long total = 0;
//         for (int i = 0; i < 26; ++i) {
//             total = (total + freq[i]) % mod;
//         }

//         return total;
//     }
// };



class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        constexpr int MOD = 1e9 + 7;
        long cnts[26] = {}; // freq of each letter a-z

        // Step 1: Count initial characters in the string
        for (char c : s) {
            cnts[c - 'a']++;
        }

        // Step 2: While t >= 26, simulate one full 26-step cycle
        while (t >= 26) {
            long temp[26] = {};

            // Each letter a to y shifts to next letter (i → i+1)
            for (int i = 0; i < 25; ++i) {
                temp[i + 1] += cnts[i];
            }

            // Special case: z → a and b
            temp[0] += cnts[25];
            temp[1] += cnts[25];

            // Apply the changes
            for (int i = 0; i < 26; ++i) {
                cnts[i] = (cnts[i] + temp[i]) % MOD;
            }

            t -= 26; // one full cycle processed
        }

        // Step 3: Handle remaining t steps smartly without simulating
        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnts[i]) % MOD;

            // If letter shifts past 'z', it becomes like z (→ a + b), so add once more
            if (i + t >= 26) {
                ans = (ans + cnts[i]) % MOD;
            }
        }

        return (int)ans;
    }
};
