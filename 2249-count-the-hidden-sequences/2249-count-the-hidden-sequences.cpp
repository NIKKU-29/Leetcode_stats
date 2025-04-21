class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxi = 0;
        long long mini = 0;
        long long sum = 0;

        for(auto elem : differences) {
            sum += elem;
            maxi = max(maxi, sum);
            mini = min(mini, sum);
        }

        if (maxi - mini > upper - lower)
            return 0;

        return (upper - lower) - (maxi - mini) + 1;
    }
};
