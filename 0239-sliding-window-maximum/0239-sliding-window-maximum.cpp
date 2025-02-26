class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>dq;
            vector<int>ans;
            int n=nums.size();

            int j=0;
            int i=0;

            while(j < n)
            {
                while(!dq.empty() && dq.back() < nums[j])
                {
                    dq.pop_back();
                }

                dq.push_back(nums[j]);

                j++;

                if(j-i == k) //window size mett
                {
                    ans.push_back(dq.front());
                    
                    if(dq.front() == nums[i]) dq.pop_front();
                    i++;
                }
            }

            return ans;
    }
};