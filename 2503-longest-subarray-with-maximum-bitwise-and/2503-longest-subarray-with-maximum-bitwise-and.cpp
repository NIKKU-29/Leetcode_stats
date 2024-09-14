class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
    
        int target= * max_element(nums.begin(),nums.end());
        int maxfreq=0;
        int currfreq=0;
    

        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]==target)
            {
                currfreq++;
                maxfreq=max(maxfreq,currfreq);
            }

            else{
                currfreq=0;
            }
            
        }

            return maxfreq;
    }
};