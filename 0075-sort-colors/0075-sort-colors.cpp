class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size() -1 ;
        int start = 0;
        int end = n;
        int mid = start;

        while(mid <= end)
        {
            if(nums[mid] == 0) 
            {
                swap(nums[mid],nums[start]);
                mid++;
                start++;
            }

            else if(nums[mid]== 1)
            {
                mid++;
            }

            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }


    }
};