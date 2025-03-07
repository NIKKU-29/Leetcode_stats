class Solution {
public:

    int m,n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        m = mat.size();
        n= mat[0].size();
        
        queue<pair<int,int>>q;

        for(int  i=0 ;i< m ;i++)
        {
            for(int j=0 ; j< n ;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }

                else{
                    mat[i][j] = -1; //unvisted;
                }
            }
        }

        vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            int x =q.front().first;
            int y =q.front().second;
            q.pop();

            for(auto elem : directions)
            {
                int newx = x + elem[0];
                int newy = y + elem[1];

                if(newx < m && newx >=0 && newy < n && newy >=0 && mat[newx][newy] == -1)
                {
                    mat[newx][newy] = mat[x][y] + 1;
                    q.push({newx,newy});
                }
            }
        }

        return mat;
    }
};