class Solution {
public:
    typedef vector<vector<int>> Matrix;
    int M = 1e9 + 7;

    Matrix MatrixMultiplication(Matrix& A, Matrix& B) {
        Matrix C(26, vector<int>(26, 0));

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    // Correct matrix multiplication: C[i][j] += A[i][k] * B[k][j]
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j] % M) % M;
                }
            }
        }
        return C;
    }

    Matrix MatrixExponentiation(Matrix& base, int exponent) {
        if(exponent == 0) {
            Matrix I(26, vector<int>(26, 0));
            for(int i = 0; i < 26; i++) {
                I[i][i] = 1;
            }
            return I;
        }

        Matrix half = MatrixExponentiation(base, exponent/2);
        Matrix result = MatrixMultiplication(half, half);

        if(exponent % 2 == 1) {
            result = MatrixMultiplication(result, base);
        }

        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Initialize frequency vector properly
        vector<int> InitialFreq(26, 0);
        for(auto elem : s) {
            InitialFreq[elem - 'a']++;
        }

        // Create transition matrix
        Matrix T(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++) {
            for(int add = 1; add <= nums[i]; add++) {
                // T[j][i] means character i transforms to character j
                T[(i + add) % 26][i]++;
            }
        }

        // Calculate T^t
        Matrix result = MatrixExponentiation(T, t);

        // Calculate final frequencies
        vector<int> FinalFreq(26, 0);
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                // Apply transformation: final_freq[i] += T^t[i][j] * initial_freq[j]
                FinalFreq[i] = (FinalFreq[i] + 1LL * result[i][j] * InitialFreq[j] % M) % M;
            }
        }

        // Sum up all frequencies
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans = (ans + FinalFreq[i]) % M;
        }

        return ans;
    }
};