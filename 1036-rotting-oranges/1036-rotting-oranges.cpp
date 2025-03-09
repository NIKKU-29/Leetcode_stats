class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        
        int orange = 0;
        int m= grid.size();
        int n = grid[0].size();
        int time=-1;
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
                        grid[newx][newy] = 2;
                        orange--;
                        
                    }
                }
            }

            time++;
        }

        return orange == 0 ? time : -1;
  }
};