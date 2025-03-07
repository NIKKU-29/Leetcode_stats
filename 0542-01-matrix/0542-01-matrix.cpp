class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n= mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        
        queue<pair<int,int>>q;

        for(int  i=0 ;i< m ;i++)
        {
            for(int j=0 ; j< n ;j++)
            {
                if(mat[i][j] == 0)
                {
                    result[i][j]=0;
                    q.push({i,j});
                }

            }
        }

        vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto elem : directions)
            {
                int newx = x + elem[0];
                int newy = y + elem[1];

                if(newx < m && newx >=0 && newy < n && newy >=0 && result[newx][newy] == -1)
                {
                    result[newx][newy] = result[x][y] + 1;
                    q.push({newx,newy});
                }
            }
        }

        return result;
    }
};