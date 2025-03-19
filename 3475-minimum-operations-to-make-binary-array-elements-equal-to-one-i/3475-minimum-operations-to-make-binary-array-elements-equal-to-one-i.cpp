class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        bool loop = false;
        int count =0;
        for(int i =0 ;i<= n-3 ;i++)
        {
            bool loop = false;
            for(int j = 0 ; j < 3 ; j++)
            {
                if(j == 0  && nums[i+j] == 1)
                {
                    loop = true;
                    break;
                }

                nums[i+j]=!nums[i+j];
                
            }

            if(loop == false) count++;
        }

        for(auto elem : nums)
        {
            if(!elem) return -1;
        }

        return count;
    }
};