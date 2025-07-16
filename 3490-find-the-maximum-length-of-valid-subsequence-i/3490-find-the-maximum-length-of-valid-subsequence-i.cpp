class Solution {
public:

    int maximumLength(vector<int>& nums) {
        
        int ans = 0;
        int prev = -1;
        int count = 0;
        int longodd = 0;
        int longeven = 0;

        for (auto current : nums)
        {
            
            if(current % 2 == 0) longeven++;
            if(current % 2 == 1) longodd++;

            if (prev == -1)
            {
                prev = current;
                count++;
            }
            else
            {
                if ((prev & 1) != (current & 1)) // alternating parity
                {
                    count++;
                    prev = current;
                }
            }
            ans = max(ans, count);
            
        }
        return max(ans,max(longodd,longeven));        
    }
};
