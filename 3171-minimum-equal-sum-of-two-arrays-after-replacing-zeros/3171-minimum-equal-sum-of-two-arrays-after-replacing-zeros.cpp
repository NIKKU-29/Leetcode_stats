class Solution {
public:

    typedef long long ll;

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        ll Z1 = 0;
        ll Z2 = 0;
        ll sum1 = 0;
        ll sum2 = 0;
        

        for(ll elem : nums1)
        {
            
            sum1+=elem;

            if(elem == 0) 
            {
                Z1++;
                sum1++;
            }
        } 

        for(ll elem : nums2)
        {
            sum2+=elem;

             if(elem == 0)
             {
                 Z2++;
                 sum2++;
            }
        }

        if(Z1 == 0 && sum2 > sum1 || Z2 == 0 && sum1 > sum2) return -1;

        return max(sum1,sum2);
       
        
    }
};