class Solution {
public:
    int minTimeToReach(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        using T = tuple<int, int, int, int>; // time, x, y, isFast (1 or 0)
        
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0, 1}); // Start at (0,0), time = 0, first move is fast (1s)
        
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        
        while (!pq.empty()) {
            auto [currTime, x, y, isFast] = pq.top(); pq.pop();
            
            if (x == n - 1 && y == m - 1)
                return currTime;
            
            if (visited[x][y][isFast])
                continue;
            
            visited[x][y][isFast] = true;
            
            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int moveDuration = isFast ? 1 : 2;
                    int nextTime = max(currTime , M[newX][newY]) + moveDuration;
                    pq.push({nextTime, newX, newY, 1 - isFast});
                }
            }
        }
        
        return -1;
    }
};
