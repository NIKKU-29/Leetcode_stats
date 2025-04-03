class Solution {
public:
    
    typedef long long ll;

    long long maximumTripletValue(vector<int>& nums) {

        ll maxSofar = 0;
        ll max3 = 0 ;
        ll maxdiff = 0;

        for(ll elem : nums)
        {
            max3= max(max3,maxdiff * elem);
            // cout<<max3<<"-";
            maxdiff = max(maxdiff,maxSofar - elem);
            maxSofar = max(maxSofar,elem);
        }

        return max3;
        
    }
};