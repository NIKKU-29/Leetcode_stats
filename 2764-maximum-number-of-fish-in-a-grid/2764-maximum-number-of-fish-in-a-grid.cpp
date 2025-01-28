class Solution {
public:

    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        // Base case: Out of bounds or the cell is land (0)
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int fish = grid[i][j]; 
        grid[i][j] = 0;        

        // Explore all 4 directions
        fish += dfs(i + 1, j, n, m, grid); // Down
        fish += dfs(i - 1, j, n, m, grid); // Up
        fish += dfs(i, j + 1, n, m, grid); // Right
        fish += dfs(i, j - 1, n, m, grid); // Left

        return fish; 
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0;             // Track maximum fish
        int m = grid.size();      // Number of rows
        int n = grid[0].size();   // Number of columns

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) { // Start from a water cell
                    maxi = max(maxi, dfs(i, j, n, m, grid));
                }
            }
        }

        return maxi; // Return the maximum fish that can be caught
    }
};
