class Solution {
public:

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis, auto& dirs) {
    int n = grid.size(), m = grid[0].size();
    
    if(x == n-1 && y == m-1) return true;
    
    vis[x][y] = true;

    for(auto d : dirs[grid[x][y]]) {
        int nx = x + d[0];
        int ny = y + d[1];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;

        for(auto back : dirs[grid[nx][ny]]) {
            if(nx + back[0] == x && ny + back[1] == y) {
                if(dfs(nx, ny, grid, vis, dirs)) return true;
            }
        }
    }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<vector<int>>> dirs = {
                                            {},
                                            {{0,-1},{0,1}},   
                                            {{-1,0},{1,0}},    
                                            {{0,-1},{1,0}},    
                                            {{0,1},{1,0}},     
                                            {{0,-1},{-1,0}},   
                                            {{0,1},{-1,0}}     
                                        };


        return dfs(0,0,grid,vis,dirs);
    }
};

// class Solution {
// public:
//     bool hasValidPath(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // Directions for each type
//         vector<vector<vector<int>>> dirs = {
//             {}, // dummy (0 index not used)
//             {{0,-1},{0,1}},    // 1: left, right
//             {{-1,0},{1,0}},    // 2: up, down
//             {{0,-1},{1,0}},    // 3: left, down
//             {{0,1},{1,0}},     // 4: right, down
//             {{0,-1},{-1,0}},   // 5: left, up
//             {{0,1},{-1,0}}     // 6: right, up
//         };

//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         queue<pair<int,int>> q;

//         q.push({0,0});
//         vis[0][0] = true;

//         while(!q.empty()) {
//             auto [x,y] = q.front();
//             q.pop();

//             if(x == n-1 && y == m-1) return true;

//             for(auto d : dirs[grid[x][y]]) {
//                 int nx = x + d[0];
//                 int ny = y + d[1];

//                 if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//                 if(vis[nx][ny]) continue;

                
//                 for(auto back : dirs[grid[nx][ny]]) {
//                     if(nx + back[0] == x && ny + back[1] == y) {
//                         vis[nx][ny] = true;
//                         q.push({nx, ny});
//                         break;
//                     }
//                 }
//             }
//         }

//         return false;
//     }