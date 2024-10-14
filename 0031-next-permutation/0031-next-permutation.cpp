class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        
        // Step 1: Find the first decreasing element from the right
        for(int i = n - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                index = i - 1;  // Found the index to swap
                break;
            }
        }


        // Step 2: If we found a decreasing element (i.e., nums[index] exists)
        if(index != -1) {

            int swapper=index;
            // Find the smallest element larger than nums[index], starting from index + 1
            for(int i = n-1 ; i >= index+1; i--) {
                if(nums[i] > nums[index]) {
                    // Keep swapping until the last element larger than nums[index] is found
                   swapper=i;
                    break;  // Once swapped, we don't need to continue the loop
                }
            }

             swap(nums[index],nums[swapper]);
        }


        // Step 3: Reverse the suffix starting from index + 1
        reverse(nums.begin() + index + 1, nums.end());
    }
};
