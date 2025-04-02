class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long maxSofar = 0;
        long long max3 = 0 ;
        long long maxdiff = 0;

        for(long long elem : nums)
        {
            max3= max(max3,maxdiff * elem);
            maxSofar = max(maxSofar,elem);
            maxdiff = max(maxdiff,maxSofar - elem);
        }

        return max3;
        
    }
};