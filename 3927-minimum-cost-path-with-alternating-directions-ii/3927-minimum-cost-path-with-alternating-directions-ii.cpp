class Solution {
public:
    typedef tuple<long long, int, int, int> State; // {cost, x, y, time_parity}
    int M, N;
    vector<pair<int,int>> direction = {{0,1},{1,0}};  // right and down

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        M = m;
        N = n;

        // dp[x][y][parity] = min cost to reach (x,y) at given parity
        vector<vector<vector<long long>>> dp(M, vector<vector<long long>>(N, vector<long long>(2, LLONG_MAX)));
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at (0,0), time=1 (odd), cost = entry cost (1*1=1)
        pq.emplace(1, 0, 0, 1); // cost, x, y, time_parity
        dp[0][0][1] = 1;

        while (!pq.empty()) {
            auto [cost, x, y, parity] = pq.top(); pq.pop();

            // Goal reached
            if (x == M - 1 && y == N - 1)
                return cost;

            // Already found a better path
            if (dp[x][y][parity] < cost) continue;

            if (parity == 1) { // odd time, can move
                for (auto [dx, dy] : direction) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < M && ny < N) {
                        long long entryCost = 1LL * (nx + 1) * (ny + 1);
                        long long newCost = cost + entryCost;
                        if (newCost < dp[nx][ny][0]) {
                            dp[nx][ny][0] = newCost;
                            pq.emplace(newCost, nx, ny, 0);
                        }
                    }
                }
            } else { // even time, must wait
                long long wait = waitCost[x][y];
                long long newCost = cost + wait;
                if (newCost < dp[x][y][1]) {
                    dp[x][y][1] = newCost;
                    pq.emplace(newCost, x, y, 1);
                }
            }
        }

        return -1; // unreachable
    }
};
