class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        using T = tuple<int, int, int, int>; // time, x, y, isFast

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0, 1}); // Start at (0,0), time=0, next move is fast (1s)

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [currTime, x, y, isFast] = pq.top(); pq.pop();

            if (x == n - 1 && y == m - 1)
                return currTime;

            if (visited[x][y][isFast])
                continue;

            visited[x][y][isFast] = true;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int moveDuration = isFast ? 1 : 2;
                    int nextTime = max(currTime , moveTime[nx][ny]) + moveDuration;
                    pq.push({nextTime, nx, ny, 1 - isFast});
                }
            }
        }

        return -1; // unreachable
    }
};
