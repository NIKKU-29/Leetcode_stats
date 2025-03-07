class Solution {
public:
    int m, n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Initialize queue and visited array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true; // Mark visited
                } else {
                    mat[i][j] = -1; // Placeholder for distance
                }
            }
        }

        // Step 2: BFS traversal
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto elem : directions) {
                int newx = x + elem[0];
                int newy = y + elem[1];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newx][newy]) {
                    mat[newx][newy] = mat[x][y] + 1;
                    q.push({newx, newy});
                    visited[newx][newy] = true; // Mark as visited
                }
            }
        }

        return mat;
    }
};
