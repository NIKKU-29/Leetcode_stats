class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>rows(m,0);
        vector<int>colm(n,0);
        vector<pair<int,int>>marker;

        for(int i=0 ;i< m ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(grid[i][j]==1)
                {
                    rows[i]++;
                    colm[j]++;
                    marker.push_back({i,j});
                }
            }
        }

        int sum=0;

            for(auto elem : marker)
            {
                int A=elem.first;
                int B=elem.second;
                if(rows[A] > 1 || colm[B] > 1)
                {
                    sum++;
                }   
            }
                
        
        return sum;

    }
};