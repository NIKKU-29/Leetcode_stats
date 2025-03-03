class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        deque<int>dq;
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] > pivot)
            {
                dq.push_back(nums[i]);
            }

            else if(nums[i] == pivot)
            {
                dq.push_front(nums[i]);
            }
        }

        for(int i=n-1 ;i >= 0 ;i--)
        {
            if(nums[i] < pivot)
            {
                dq.push_front(nums[i]);
            }
        }

        vector<int>ans;

        for(auto elem : dq)
        {
            ans.push_back(elem);
        }

        return ans;

    }
};