// class Solution {
// public:
    
//     vector<int>ans;

//     void solver(int idx,vector<int>&curr,vector<int>& nums)
//     {
//         if(idx == nums.size())
//         {
//             if(curr.size() > ans.size())
//             {
//                 ans = curr;
//             }

//             return;
//         }



//         if(curr.empty() || curr.back() % nums[idx] == 0 || nums[idx] % curr.back() == 0)
//         {
//             //we have two options
//             curr.push_back(nums[idx]);
//             solver(idx+1,curr,nums);
//             curr.pop_back();
//             solver(idx+1,curr,nums);
//         }

//         else{
//                 solver(idx+1,curr,nums);
//         }


//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {

//         vector<int>curr;
//         sort(nums.begin(),nums.end());
//         solver(0,curr,nums);
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // dp[i] = length of largest divisible subset ending with nums[i]
        vector<int> dp(n, 1);
        
        // prev[i] = previous index that forms the subset with nums[i]
        vector<int> prev(n, -1);
        
        // Track the index of the element with the maximum subset size
        int max_idx = 0;
        
        // Fill dp array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If nums[i] is divisible by nums[j] or vice versa
                // and including nums[i] leads to a larger subset
                if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            
            // Update max_idx if needed
            if (dp[i] > dp[max_idx]) {
                max_idx = i;
            }
        }
        
        // Reconstruct the largest divisible subset
        vector<int> result;
        while (max_idx != -1) {
            result.push_back(nums[max_idx]);
            max_idx = prev[max_idx];
        }
        
        // Since we constructed the result in reverse order
        reverse(result.begin(), result.end());
        
        return result;
    }
};