class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& W) {
        int m = W.size();
        int n = W[0].size();
        queue<pair<int, int>> q;

        // Initialize the queue with all water cells and mark them as visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (W[i][j] == 1) {
                    W[i][j] = 0; // Distance from itself is 0
                    q.push({i, j});
                } else {
                    W[i][j] = -1; // Unvisited land cells
                }
            }
        }

        // Direction vectors for 4 possible moves
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check boundaries and if the cell is unvisited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && W[nx][ny] == -1) {
                    W[nx][ny] = W[x][y] + 1; // Update distance
                    q.push({nx, ny}); // Add to the queue for further processing
                }
            }
        }

        return W;
    }
};
