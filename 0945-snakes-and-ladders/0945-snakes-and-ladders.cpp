class Solution {
public:

    typedef pair<int,int> pp;
    int n = 0;

    // Helper to map 1D cell number to 2D coordinates
    pp helper(int num)
    {
        int row = n - 1 - (num - 1) / n;
        int col = (num - 1) % n;

        if ((n - 1 - row) % 2 == 1) col = n - 1 - col;

        return {row , col};
    } 

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {cell_number, steps}
        
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == n * n) return steps;

            for (int move = 1; move <= 6; ++move) {
                int next = curr + move;
                if (next > n * n) break;

                auto [r, c] = helper(next);
                if (board[r][c] != -1) {
                    next = board[r][c];  // Move via snake or ladder
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1; // Unreachable
    }
};
