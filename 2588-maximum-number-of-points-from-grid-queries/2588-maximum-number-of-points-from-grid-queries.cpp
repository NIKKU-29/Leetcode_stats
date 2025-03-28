// class Solution {
// public:

//     vector<vector<int>>directions = { {+1,0} , {-1,0} , {0, +1} ,{0, -1}};

//     int solver(int idx,int idy,int limit,vector<vector<int>>& grid,vector<vector<bool>>&visited)
//     {
//         int m = grid.size();
//         int n = grid[0].size();

//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
//         q.push({idx,idy});
//         visited[idx][idy] = true;
//         int points =1;

//         while(!q.empty())
//         {
//             int siz = q.size();

//             while(siz--)
//             {
//                 pair<int,int>topi = q.front();
//                 int oldx = topi.first;
//                 int oldy = topi.second;
//                 q.pop();
               

//                 for(auto elem : directions)
//                 {
//                     int newx = oldx + elem[0];
//                     int newy = oldy + elem[1];

//                         if(newx < m && newy < n && newx >= 0 && newy >= 0 && visited[newx][newy] == false && grid[newx][newy] < limit)
//                         {
//                             points++;
//                             visited[newx][newy] = true;
//                             q.push({newx,newy});
//                         }
//                 }
//             }
//         }

//         return points;
//     }


//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

//         int m = grid.size();
//         int n = grid[0].size();
//         vector<int>ans;
//         for(auto limit : queries)
//         {
//             vector<vector<bool>> visited(m, vector<bool>(n, false));
//             int point = 0;
//             if(grid[0][0] < limit) 
//             {
//                 point += solver(0,0,limit,grid,visited);
//             }

//             ans.push_back(point);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> ans(queries.size(), 0);
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end()); // Sort queries to process efficiently

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int totalCount = 0, lastLimit = 0;

        for (auto [limit, index] : sortedQueries) {
            while (!pq.empty() && pq.top().first < limit) {
                auto [val, pos] = pq.top(); pq.pop();
                int x = pos.first, y = pos.second;
                totalCount++;

                vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                for (auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            ans[index] = totalCount; // Store answer for this query
        }

        return ans;
    }
};
