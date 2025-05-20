class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int>vec(n,0);

        for(auto elem : queries)
        {
            int start = elem[0];
            int end = elem[1];

            vec[start]--;
            if(end+1 < n) vec[end+1]++;

        }

        vector<int>presum;
        int runningsum=0;
        for(auto elem : vec)
        {
            runningsum+=elem;
            presum.push_back(runningsum);
        }

        for(int i = 0 ;i < n ; i++)
        {
            if(nums[i] + presum[i] > 0) return false;
        }

        return true;
        
    }
};