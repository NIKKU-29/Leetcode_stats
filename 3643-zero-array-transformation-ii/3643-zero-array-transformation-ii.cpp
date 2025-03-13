
class Solution {
public:

    bool solver(int mid, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> diffArr(n + 1, 0);  // Use long long
        vector<long long> Presum(n, 0);  

        for (int i = 0; i < mid; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int value = queries[i][2];

            diffArr[start] += value;
            diffArr[end + 1] -= value;
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diffArr[i];
            Presum[i] = sum;
        }

        for (int i = 0; i < n; i++) {
            if (Presum[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        if (accumulate(nums.begin(), nums.end(), 0LL) == 0) return 0;  // Use 0LL

        int l = 0, r = n, ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solver(mid, nums, queries)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
