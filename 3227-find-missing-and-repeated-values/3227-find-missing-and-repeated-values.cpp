class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

            int n = grid.size();
            int Sz = n*n;

            vector<int>vec(Sz+1);


            for(int i=0 ;i< n ;i++)
            {
                for(int j=0 ;j< n ;j++)
                {
                    vec[grid[i][j]]++;
                }
            }

            int extra=0;
            int swapped=0;
            
            for(int i=1 ;i<Sz+1 ;i++)
            {
                if(vec[i] == 2)
                {
                    extra = i;
                }

                if(vec[i] == 0)
                {
                    swapped = i;
                }
            }


            return {extra,swapped};
            

    }
};