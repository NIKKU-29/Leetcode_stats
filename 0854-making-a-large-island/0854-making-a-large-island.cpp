class Solution {
public:

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int FindArea(int i ,int j , vector<vector<int>>& grid,vector<vector<int>>&island,int id)
    {
        int n=grid.size();
        int m=grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || island[i][j]!=0) {
            return 0;
        }

        island[i][j]=id;

      

        int left=FindArea(i-1,j,grid,island,id);
        int right=FindArea(i+1,j,grid,island,id);
        int up=FindArea(i,j-1,grid,island,id);
        int down=FindArea(i,j+1,grid,island,id);

        return 1+left+right+up+down;
    }

    int largestIsland(vector<vector<int>>& grid) {
        
        //calulating what all 1 can give for now no 0 has been changed
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>island(n,vector<int>(m,0));
        unordered_map<int,int>landID;
        int id=2;

        for(int i=0;i<n;i++)
        {
            for(int j=0 ;j<m ;j++)
            {
                if(grid[i][j]==1 && island[i][j]==0)
                {
                    int size=FindArea(i,j,grid,island,id);
                    landID[id]=size;
                    ans=max(ans,size);
                    id++;
                }
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0 ;j<m ;j++)
            {
                set<int>NeighboursID;
                if(grid[i][j]==0)
                {
                    for (auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m && island[ni][nj] > 1) {
                            NeighboursID.insert(island[ni][nj]);
                        }
                    }
               }

               int currArea=1;

               for(auto elem : NeighboursID)
               {
                    currArea+=landID[elem];
               }

               ans=max(ans,currArea);
            }
        }
        
    
        return ans==0 ? m*n : ans;
    }
};