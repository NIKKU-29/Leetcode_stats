class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        constexpr int MOD = 1e9 + 7;
        vector<long long> cnts(26, 0); // freq of each letter a-z

        // Step 1: Count initial characters in the string
        for (char c : s) {
            cnts[c - 'a']++;
        }

        // Step 2: Process all t transformations directly
        for (int step = 0; step < t; ++step) {
            vector<long long> next(26, 0);
            
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] == 0) continue;
                
                if (i == 25) { // 'z' becomes 'a' and 'b'
                    next[0] = (next[0] + cnts[i]) % MOD;
                    next[1] = (next[1] + cnts[i]) % MOD;
                } else { // other letters shift by 1
                    next[i + 1] = (next[i + 1] + cnts[i]) % MOD;
                }
            }
            
            cnts = next;
        }

        // Calculate total length after all transformations
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + cnts[i]) % MOD;
        }

        return static_cast<int>(total);
    }
};