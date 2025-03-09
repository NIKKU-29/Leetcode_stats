class Solution {
public:

    int solver(int&oranges ,vector<vector<int>>& grid ,queue<pair<int,int>>&q)
    {
        int m =grid.size();
        int n=grid[0].size();
        int time=0;
        
        vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
           
                for(auto elem : directions)
                {
                    int newx = x + elem[0];
                    int newy = y + elem[1];

                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1)
                    {
                        q.push({newx,newy});
                        grid[newx][newy] = 0;
                        oranges--;
                        
                    }
                }
            }

            time++;
        }

        return oranges == 0 ? time-1 : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int orange = 0;
        int m= grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0 ;i<m ;i++)
        {
            for(int j=0 ;j< n ;j++)
            {
                    if(grid[i][j] ==2)
                    {
                        q.push({i, j});
                    }

                    if(grid[i][j] == 1) orange++;
            }
        }

        if(orange == 0 ) return 0;

        return solver(orange,grid,q);
  }
};