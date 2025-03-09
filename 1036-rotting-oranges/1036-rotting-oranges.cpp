class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> holder;
        int time = 0;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    holder.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        while (!holder.empty()) {
            int change = 0;
            int size = holder.size();

            while (size) {
                pair<int, int> elem;
                elem = holder.front();
                holder.pop();

                int infx = elem.first;
                int infy = elem.second;

                int x[4] = {1, -1, 0, 0};
                int y[4] = {0, 0, 1, -1};

                for (int i = 0; i < 4; i++) {
                    int sprdx = infx + x[i];
                    int sprdy = infy + y[i];

                    if (sprdx >= 0 && sprdx < m && sprdy >= 0 && sprdy < n && grid[sprdx][sprdy] == 1) {
                        holder.push({sprdx, sprdy});
                        grid[sprdx][sprdy] = 2;
                        fresh--;
                        change++;
                    }
                }
                size--;
            }

            if (change != 0) {
                time++;
            }
        }

        if (fresh != 0) {
            return -1;
        }

        return  time;
    }
};
