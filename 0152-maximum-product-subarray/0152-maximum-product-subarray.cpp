class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prod=1;
        int n=nums.size();
        int ans=INT_MIN;

        for(int i=0 ;i< n;i++)
        {
            prod*=nums[i];
            ans=max(ans,prod);
            if(prod<0) prod=1;
        }


        return ans;
    }
};