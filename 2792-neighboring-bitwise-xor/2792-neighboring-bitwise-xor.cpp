class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
         int n = derived.size();
        int xorSum = 0;

        // Compute XOR of all derived elements
        for (int num : derived) {
            xorSum ^= num;
        }

        // If XOR sum is 0, a valid array exists
        return xorSum == 0;
    }
};