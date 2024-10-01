class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int paircount = 0;

        // Count occurrences of remainders when divided by k
        for (int elem : arr) {
            int mod = (elem % k + k) % k;  // To handle negative values correctly
            mp[mod]++;
        }

        // Now check pairs based on remainders
        for (int i = 0; i < arr.size(); i++) {
            int mod = (arr[i] % k + k) % k;

            if (mod == 0) {
                // Special case for elements divisible by k (i.e., mod == 0)
                if (mp[mod] % 2 != 0) {
                    return false; // Cannot form pairs if odd count
                }
            } else {
                int target = k - mod;  // We need another element whose mod is `k - mod`
                if (mp[mod] != mp[target]) {
                    return false;  // If counts don't match, pairs cannot be formed
                }
            }
        }

        return true;
    }
};
