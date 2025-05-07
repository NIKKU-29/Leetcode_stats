class Solution {
public:
    int minTimeToReach(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        
        // Min-heap: {time, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});

        while (!q.empty()) {
            auto p = q.top(); q.pop();
            int currtime = p.first;
            int x = p.second.first;
            int y = p.second.second;

            if (x == n - 1 && y == m - 1) return currtime;
            if (currtime >= dp[x][y]) continue;
            dp[x][y] = currtime;

            for (auto elem : directions) {
                int newx = x + elem.first;
                int newy = y + elem.second;

                if (newx >= 0 && newx < n && newy >= 0 && newy < m && M[newx][newy] != -1) {
                    int nextTime = max(currtime, M[newx][newy]) + 1;
                    q.push({nextTime, {newx, newy}});
                }
            }
        }

        return -1;
    }
};
