class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n= mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        
        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++){  // ✅ Corrected Loop Order
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};

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