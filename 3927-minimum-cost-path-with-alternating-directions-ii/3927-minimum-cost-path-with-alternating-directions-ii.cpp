class Solution {
public:
    struct State {
        long long cost;
        int x, y, tmod;

        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0][1] = 1;  // Starting with time = 1, cost = (0+1)*(0+1)
        pq.push({1, 0, 0, 1}); // cost, x, y, time_parity

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}};  // Down, Right

        while (!pq.empty()) {
            auto [currCost, x, y, tmod] = pq.top(); pq.pop();

            if (x == m - 1 && y == n - 1)
                return currCost;

            if (dist[x][y][tmod] < currCost) continue;

            if (tmod == 1) { // Move time
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < m && ny < n) {
                        long long moveCost = 1LL * (nx + 1) * (ny + 1);
                        if (currCost + moveCost < dist[nx][ny][0]) {
                            dist[nx][ny][0] = currCost + moveCost;
                            pq.push({dist[nx][ny][0], nx, ny, 0});
                        }
                    }
                }
            } else { // Wait time
                long long wait = waitCost[x][y];
                if (currCost + wait < dist[x][y][1]) {
                    dist[x][y][1] = currCost + wait;
                    pq.push({dist[x][y][1], x, y, 1});
                }
            }
        }

        return -1; // Should never reach here
    }
};
