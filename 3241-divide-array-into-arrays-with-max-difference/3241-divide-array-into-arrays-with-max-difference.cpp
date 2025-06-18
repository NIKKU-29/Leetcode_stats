class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n ; i+=3)
        {
            vector<int>curr;
            
            if(nums[i+1] - nums[i] > k || nums[i+2] - nums[i+1]  > k || nums[i+2] - nums[i] > k)
            {
                return {};
            }

            else{
                
                curr.push_back(nums[i]);
                curr.push_back(nums[i+1]);
                curr.push_back(nums[i+2]);
            }
           
            
            ans.push_back(curr);
        }


        return ans;

    }
};