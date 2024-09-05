class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumH = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sumH += rolls[i];
        }

        int totalRolls = rolls.size() + n;  // Total number of rolls
        int totalSum = mean * totalRolls;   // Total expected sum
        int leftSum = totalSum - sumH;      // Remaining sum to distribute

        // Check if it's possible to distribute leftSum across n dice
        if (leftSum < n || leftSum > 6 * n) {
            return {};  // Impossible to distribute
        }

        // Base value for each die roll and remainder
        int add = leftSum / n;
        int remaining = leftSum % n;

        vector<int> result(n, add);  // Fill with base value

        // Distribute the remaining value across the first 'remaining' positions
        for (int i = 0; i < remaining; ++i) {
            result[i]++;
        }

        return result;
    }
};
