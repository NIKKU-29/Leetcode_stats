class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        // int ans=0;
        // int n=nums.size();
        // for(int i=0 ;i< n ;i++)
        // {
        //     int j=i;
        //     int sum=nums[j];
        //     while(j < n-1 &&  nums[j]<nums[j+1])
        //     {
        //         sum+=nums[j+1];
        //         j++;
        //     }

        //     ans=max(ans,sum);
        // }


        //two pinetrs

        /* 12 17 15 13 10 11 12
                ?   break
                29 til idx1
                    ? break
                    15 till idx 2
                       ? break
                        13 till idx 3
                                33 ? stop till last  
        */

        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;

        while(i<n)
        {
            sum=nums[j];

            while(j< n-1 && nums[j] < nums[j+1])
            {
                sum+=nums[j+1];
                j++;
            }

            ans=max(ans,sum);
            i=j+1;
            j++;
        }

        return ans;
        
    }
};