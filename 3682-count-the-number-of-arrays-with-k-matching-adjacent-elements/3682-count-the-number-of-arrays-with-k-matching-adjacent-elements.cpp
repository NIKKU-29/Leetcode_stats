class Solution {
public:
    int mod = 1e9 + 7;

    long long power(long long base, int exp) {
        long long result = 1;
        base = base % mod;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp >> 1;
        }

        return result;
    }

    int ncr(int n, int r) {
        if (r > n) return 0;

        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % mod;
            den = (den * (r - i)) % mod;
        }

        return (int)((num * power(den, mod - 2)) % mod); 
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;

        int locations = ncr(n - 1, k);
        long long locationComb = (1LL * locations * m) % mod;

        int leftLocations = n - 1 - k;
        long long remainingComb = power(m - 1, leftLocations);

        return (int)((locationComb * remainingComb) % mod);
    }
};
