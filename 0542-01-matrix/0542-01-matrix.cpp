class Solution {
public:
 

        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();   // Number of rows
        int n = mat[0].size(); // Number of columns

        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>> q;
        vector<vector<int>> result(m, vector<int>(n, -1)); // ✅ Correct dimensions

        // Step 1: Push all 0's into queue and initialize the result matrix
        for(int i = 0; i < m; i++){  // ✅ Corrected Loop Order
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Perform BFS
        while(!q.empty()){
            auto [i, j] = q.front();  // ✅ Cleaner way to extract values
            q.pop();

            for(auto& dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                // ✅ Corrected Bounds Check
                if(newi >= 0 && newi < m && newj >= 0 && newj < n && result[newi][newj] == -1){
                    result[newi][newj] = result[i][j] + 1;
                    q.push({newi, newj});
                }
            }
        }

        return result;
    }
};