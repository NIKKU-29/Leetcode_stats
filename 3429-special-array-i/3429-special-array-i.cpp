class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1) return true;

        for(int i=0 ; i< nums.size()-1 ;i++)
        {
            int sum=nums[i]+nums[i+1];
            if(sum%2==0) return false;
        }

        return true;   
    }
};