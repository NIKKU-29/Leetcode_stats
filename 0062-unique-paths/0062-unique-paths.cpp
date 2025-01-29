class Solution {
public:
 int t[101][101];

int solve(int a, int b, int m, int n) {
    if (a >= m || b >= n) return 0;
    if (a == m-1 || b == n-1) return 1; // Directly return 1 for edge cases
    if (t[a][b] != -1) return t[a][b];
    return t[a][b] = solve(a+1, b, m, n) + solve(a, b+1, m, n);
}

int uniquePaths(int m, int n) {
    memset(t, -1, sizeof(t));
    return solve(0, 0, m, n);
}
};