class Solution {
public:

//0-1 bfs

    int minimumObstacles(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;

        deque<pair<int,int>>dq;
        dq.push_front({0, 0});

        while(!dq.empty())
        {
            auto [x,y] = dq.front();
            dq.pop_front();

            for(auto elem : dir)
            {
                int nx=x+elem.first;
                int mx=y+elem.second;

                if(nx>=0 && mx>=0 && nx<n && mx<m)
                {
                    int new_dist= dist[x][y] + (grid[nx][mx]==1 ? 1 : 0);

                    if(new_dist < dist[nx][mx])
                    {

                    dist[nx][mx]=new_dist;

                    if(grid[nx][mx]==1)
                    {
                        dq.push_back({nx,mx});
                    }

                    else
                    {
                        dq.push_front({nx,mx});
                        }
                    }
                }
            }
        }


        return dist[n-1][m-1];
        
    }
};