class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        stack<int>st;

        for(int i=0 ;i<n;i++)
        {
            if(st.empty() || nums[st.top()] > nums[i])
            {
                st.push(i);
            }
        }

        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                ans=max(ans,i-st.top());
                st.pop();
            }
        }

        return ans;
    }
};