class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while(exp)
        {
            if (exp % 2 == 1) result = (result * base) % MOD;
                
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long e = (n + 1) / 2; 
        long long o = n / 2;        

        long long res = (power(5, e) * power(4, o)) % MOD;
        return res;
    }
};
