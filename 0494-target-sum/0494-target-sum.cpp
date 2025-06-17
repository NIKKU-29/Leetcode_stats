class Solution {
public:
    // int f(vector<int>& arr, int k, int i, int curr, vector<vector<int>>& mem,
    //       int& sum) {

    //     int n = arr.size();
    //     if (i == n) {
    //         if (curr == k)
    //             return 1;
    //         return 0;
    //     }

    //     if (mem[i][curr + sum] != -1)
    //         return mem[i][curr + sum];

    //     return mem[i][curr + sum] = f(arr, k, i + 1, curr - arr[i], mem, sum) +
    //                                 f(arr, k, i + 1, curr + arr[i], mem, sum);
    // }

    int findTargetSumWays(vector<int>& arr, int k) {

        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int offset = 2000;

        vector<vector<int>> mem(n + 1, vector<int>(2 * sum + 1 + offset, 0));
        mem[n][k + offset] = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int curr = -sum; curr <= sum; ++curr) {
                mem[i][curr + offset] = mem[i + 1][curr - arr[i] + offset] +
                                        mem[i + 1][curr + arr[i] + offset];
            }
        }

        return mem[0][offset];
    }
};