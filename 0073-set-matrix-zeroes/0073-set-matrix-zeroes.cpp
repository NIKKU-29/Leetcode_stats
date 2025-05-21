class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

            int n = matrix.size();
            int m = matrix[0].size();

            set<pair<int,int>>mp;

            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        mp.insert({i,j});
                    }
                }
            }


            for(auto elem : mp)
            {
                int x = elem.first;
                int y = elem.second;

                for(int i = 0 ; i < n ; i++)
                {
                    matrix[i][y] = 0;
                }

                for(int j = 0 ; j < m ; j++)
                {
                    matrix[x][j] = 0;
                }
            }

    }
};