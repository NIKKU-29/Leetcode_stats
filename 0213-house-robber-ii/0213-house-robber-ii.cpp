class Solution {
public:

    int solve(vector<int>vec)
    {
        int n=vec.size();
        if(n==0) return 0;

        int prev1=vec[0];
        int prev2=0;

        for(int i=1;i<n;i++)
        {
            int take=vec[i]+prev2;
            int notake=prev1;

            prev2=prev1;
            prev1=max(take,notake);
        }
       
       return prev1;
    }

    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int>v1;
        vector<int>v2;

        for(int i=0;i< n ;i++)
        {
            if(i!=0) v1.push_back(nums[i]);
            if(i!=n-1) v2.push_back(nums[i]);
        }


        return max(solve(v1),solve(v2));
        
    }
};