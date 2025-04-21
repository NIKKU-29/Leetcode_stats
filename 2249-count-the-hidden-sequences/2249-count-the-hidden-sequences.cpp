class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum = 0, min_sum = 0, max_sum = 0;
        
        for (int diff : differences) {
            sum += diff;
            min_sum = min(min_sum, sum);
            max_sum = max(max_sum, sum);
        }

        long long left = lower - min_sum;
        long long right = upper - max_sum;

        return max(0LL, right - left + 1);
    }
};
