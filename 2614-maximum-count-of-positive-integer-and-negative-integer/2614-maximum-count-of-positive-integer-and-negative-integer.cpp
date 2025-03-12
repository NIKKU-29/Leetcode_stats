class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int numP=0,numN=0;
        for(auto elem : nums)
        {
            if(elem > 0) numP++;
            else if(elem < 0) numN++;
        }

        return max(numP,numN);
    }
};