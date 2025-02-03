class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int ans=1;
        int n=nums.size();

        for(int i=0 ;i< n ;i++)
        {
            int counta=1;
            while( i<n-1 && nums[i] < nums[i+1])
            {
                counta++;
                i++;
            }

            ans=max(ans,counta);
        }

        for(int i=n-1 ; i>0 ;i--)
        {
            int countb=1;

            while(i>0 && nums[i] < nums[i-1])
            {
                countb++;
                i--;
            }

            ans=max(ans,countb);
        }
        

        return ans;
    }
};