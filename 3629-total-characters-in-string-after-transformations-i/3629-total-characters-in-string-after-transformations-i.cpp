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



// class Solution {
// public:
//     using Matrix = vector<vector<long long>>;
//     const int MOD = 1e9 + 7;
//     const int ALPHABET = 26;

//     Matrix multiply(Matrix &A, Matrix &B) {
//         Matrix C(ALPHABET, vector<long long>(ALPHABET, 0));
//         for (int i = 0; i < ALPHABET; i++) {
//             for (int j = 0; j < ALPHABET; j++) {
//                 for (int k = 0; k < ALPHABET; k++) {
//                     C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
//                 }
//             }
//         }
//         return C;
//     }

//     Matrix matrixPower(Matrix base, int exp) {
//         Matrix result(ALPHABET, vector<long long>(ALPHABET, 0));
//         for (int i = 0; i < ALPHABET; i++) result[i][i] = 1;

//         while (exp > 0) {
//             if (exp % 2) result = multiply(result, base);
//             base = multiply(base, base);
//             exp /= 2;
//         }
//         return result;
//     }

//     int lengthAfterTransformations(string s, int t) {
//         // Frequency vector
//         vector<long long> freq(ALPHABET, 0);
//         for (char ch : s) {
//             freq[ch - 'a']++;
//         }

//         // Transition matrix
//         Matrix T(ALPHABET, vector<long long>(ALPHABET, 0));
//         for (int i = 0; i < ALPHABET - 1; i++) {
//             T[i + 1][i] = 1; // a -> b, b -> c, ..., y -> z
//         }
//         // z -> "ab"
//         T[0][25] = 1; // z -> a
//         T[1][25] = 1; // z -> b

//         // T^t
//         Matrix T_power = matrixPower(T, t);

//         // Multiply final matrix with freq vector
//         vector<long long> finalFreq(ALPHABET, 0);
//         for (int i = 0; i < ALPHABET; i++) {
//             for (int j = 0; j < ALPHABET; j++) {
//                 finalFreq[i] = (finalFreq[i] + T_power[i][j] * freq[j] % MOD) % MOD;
//             }
//         }

//         // Total length
//         long long total = 0;
//         for (int i = 0; i < ALPHABET; i++) {
//             total = (total + finalFreq[i]) % MOD;
//         }

//         return total;
//     }
// };
