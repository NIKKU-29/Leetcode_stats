class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            int seek=target-nums[i];

            if(mp.find(seek)!=mp.end())
            {
                return {mp[seek],i};
            }

            else{

                mp[nums[i]]=i;
            }
        }
        return {};
    }
};