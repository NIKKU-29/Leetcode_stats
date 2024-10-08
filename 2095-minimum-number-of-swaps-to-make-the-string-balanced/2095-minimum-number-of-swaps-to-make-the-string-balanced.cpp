class Solution {
public:
    int minSwaps(string s) {

        int o_count=0;
        int c_count=0;

        for(auto elem : s)
        {
            if(elem == '[')
            {
                o_count++;
            }

            else{

                if(o_count>0)
                {
                    o_count--;
                }

                else{

                    c_count++;
                }
            }
        }

        return (c_count+1)/2;
        
    }
};