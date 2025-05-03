class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        //trying making top equal
        int siz = tops.size();
        int count = INT_MAX;
        

        for(int i = 1 ; i <= 6 ; i++)
        {
            int counta=0;
            int countb=0;
            
            for(int j = 0 ; j < siz ; j++ )
            {

                if(tops[j] != i && bottoms[j] == i)
                {
                    counta++;
                }

                if(tops[j] == i && bottoms[j] != i)
                {
                    countb++;
                }

                else if(tops[j] != i && bottoms[j] != i)
                {
                  
                    counta = INT_MAX;
                    countb = INT_MAX;
                    break;
                } 

            }

            count = min(min(counta,countb),count);

        }

        return count == INT_MAX ? -1 : count;
        
    }
};