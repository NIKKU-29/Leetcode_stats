class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        int n = nums.size();
        vector<int>ans;
        vector<int>mp;
        // int lastindex = -1;

        for(int i = 0 ; i < n; i++)
        {
            if(nums[i] == key)
            {
                mp.push_back(i);
                // lastindex = i;
            }
        }

        // int limit = lastindex + k < n : lastindex + k : n;

        for(int i = 0 ; i < n ; i++)
        {
            for(auto elem : mp)
            {
                if(abs(i - elem) <= k) 
                {
                    ans.push_back(i); 
                    break;
                } 
            }
        } 

        return ans;
    }
};