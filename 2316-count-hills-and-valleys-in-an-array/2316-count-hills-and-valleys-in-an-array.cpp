class Solution {
public:

    

    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 1 ; i < n - 1 ; i++)
        {
           if(nums[i] == nums[i-1]) continue; 

           int l = 0;
           for(int j = i-1 ; j>=0 ; --j)
           {
                if(nums[i] < nums[j])
                {
                    l = 1;
                    break;
                }

                else if(nums[i] > nums[j])
                {
                    l = -1;
                    break;
                }
           }
            
           int r = 0;

           for(int k = i + 1 ; k < n ; k++)
           {
                if(nums[i] < nums[k])
                {
                    r = 1;
                    break;
                }

                else if(nums[i] > nums[k])
                {
                    r = -1;
                    break;
                }
           }

            if(l == r && l != 0 && r != 0) ans++;

        }
        
        return ans;
    }
};