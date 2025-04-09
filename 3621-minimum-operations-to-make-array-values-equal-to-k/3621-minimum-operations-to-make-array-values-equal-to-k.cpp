class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        set<int>st;
        int count =0;

        for(auto elem : nums)
        {
            if(elem < k) return -1;
            else if(elem > k && !st.count(elem))
            {   
                count++;
                st.insert(elem);
            }
        }
        
        return count;
    }
};