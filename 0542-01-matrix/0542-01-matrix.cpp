#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& W) {
        int m = W.size();
        int n = W[0].size();
        queue<pair<int, int>> q;

        // Initialize the queue with all '0's and mark '1's as INT_MAX
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (W[i][j] == 0) {
                    q.push({i, j}); // Push all 0's into the queue
                } else {
                    W[i][j] = INT_MAX; // Mark 1's as unvisited
                }
            }
        }

        // Directions for BFS traversal (right, left, down, up)
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check bounds and whether the neighbor's distance can be reduced
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && W[nx][ny] > W[x][y] + 1) {
                    W[nx][ny] = W[x][y] + 1; // Update distance
                    q.push({nx, ny});        // Add neighbor to the queue
                }
            }
        }

        return W;
    }
};
