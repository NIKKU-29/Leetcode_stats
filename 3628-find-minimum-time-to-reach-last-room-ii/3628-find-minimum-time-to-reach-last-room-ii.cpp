class Solution {
public:
    int minTimeToReach(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(3, false)));
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        
        using T = tuple<int, int, int, int>; // {time, variable, x, y}
        priority_queue<T, vector<T>, greater<T>> q;

        q.push({0, -1, 0, 0});  // Start with time=0, variable=-1, x=0, y=0
        
        while (!q.empty()) {
            auto [currtime, variable, x, y] = q.top(); q.pop();
            
            int vIdx = (variable == -1) ? 0 : variable; // Map -1 → 0 index for visited

            if (visited[x][y][vIdx]) continue;
            visited[x][y][vIdx] = true;
            
            if (x == n - 1 && y == m - 1) return currtime;
            
            for (auto [dx, dy] : directions) {
                int newx = x + dx;
                int newy = y + dy;
                
                if (newx >= 0 && newx < n && newy >= 0 && newy < m) {
                    int nextTime;
                    int newVariable;
                    
                    if (variable == -1 || variable == 2) {
                        nextTime = max(currtime, M[newx][newy]) + 1;
                        newVariable = 1;
                    } else {
                        nextTime = max(currtime, M[newx][newy]) + 2;
                        newVariable = 2;
                    }

                    if (!visited[newx][newy][newVariable])
                        q.push({nextTime, newVariable, newx, newy});
                }
            }
        }
        
        return -1;
    }
};
