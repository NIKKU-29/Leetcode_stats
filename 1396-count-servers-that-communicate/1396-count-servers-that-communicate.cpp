class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>rows(m,0);
        vector<int>colm(n,0);

        for(int i=0 ;i< m ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(grid[i][j]==1)
                {
                    rows[i]++;
                    colm[j]++;
                }
            }
        }

        int sum=0;

        for(int i=0 ;i< m ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(grid[i][j]==1)
                {
                    cout<<i<<"<-><->"<<j<<endl;

                    if(rows[i] > 1 || colm[j] > 1)
                    {
                        sum++;
                        // cout<<i<<"<in><in>"<<j<<endl;
                    }   
                }
            }
        }
        
        return sum;

    }
};