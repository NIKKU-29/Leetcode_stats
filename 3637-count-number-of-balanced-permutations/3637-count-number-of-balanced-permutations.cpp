const int MOD = 1e9 + 7;
int dp[10][41][361];
static constexpr auto pascal(){
    std::array<std::array<long long, 41>, 41> a = {{0}};
    for (int i = 0; i < 41; i++){
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j <= i / 2; j++){
            long long x = a[i - 1][j - 1] + a[i - 1][j];
            if (x >= MOD)
                x -= MOD;
            a[i][j] = a[i][i - j] = x;
        }
    }
    return a;
}

class Solution {
public:

    int sum = 0, n;
    std::array<int, 10> freq = {0};
    static constexpr auto comb = pascal();
    int DFS(int i, int even, int odd, int remain){
        if (even == 0 && odd == 0 && remain == 0){
            return 1;
        }
        if (i < 0 || even < 0 || odd < 0 || remain < 0){
            return 0;
        }
        if (dp[i][even][remain] != -1){
            return dp[i][even][remain];
        }
        long long res = 0;
        int max_j = std::min(freq[i], even);
        for (int j = 0; j <= max_j; j++){
            int odd_rem = freq[i] - j;
            if (odd_rem <= odd && remain >= i * j){
                if (remain - i * j > (even - j + odd - odd_rem) * (i - 1))
                    continue;
                res = (res + comb[even][j] * comb[odd][odd_rem] % MOD *
                    DFS(i - 1, even - j, odd - odd_rem, remain - i * j) % MOD) % MOD;
            }
        }
        return dp[i][even][remain] = res;
    }
    int countBalancedPermutations(string num) {
        n = num.size();
        for (char c : num) {
            int x = c - '0';
            freq[x]++;
            sum += x;
        }
        if (sum & 1)
            return 0;
        sum /= 2;
        int oddLen = n / 2, evenLen = n - oddLen;

        std::memset(dp, -1, sizeof(dp));
        return DFS(9, evenLen, oddLen, sum);
    }
};