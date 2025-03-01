class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
         
        int n = nums.size();

        

        for(int i=1 ;i< n ;i++)
        {
            if(nums[i] == nums[i-1])
            {
                nums[i-1]*=2;
                nums[i]=0;
            }
        }

        vector<int>ans;

        for(auto elem : nums)
        {
            if(elem != 0)
            {
                ans.push_back(elem);
            }
        }

        while(ans.size() != n)
        {
            ans.push_back(0);
        }

        return ans;
    }
};