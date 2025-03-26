class Solution {
public:


    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid[0].size();
        int n = grid.size();
        int siz = m * n;

        vector<int>vec;

         for(int i=0 ; i < siz ; i++)
            {
                int row = i/m;
                int col = i%m;
                vec.push_back(grid[row][col]);
            }
    
        sort(vec.begin(),vec.end());
        int median = vec[siz/2];
        int count=0;

        for(auto elem : vec)
        {
            int times = abs(median - elem);
            if(times % x) return -1;
            else count+=(times / x);
        }
        
        return count;
    }
};