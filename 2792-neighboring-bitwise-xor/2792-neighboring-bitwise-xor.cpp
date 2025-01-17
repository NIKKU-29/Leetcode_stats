class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
          int n = derived.size();

        // Edge case: Single element
        if (n == 1) {
            return derived[0] == 0; // Only valid if derived[0] == 0
        }

        // Initialize two arrays for original possibilities
        vector<int> og1(n), og2(n);

        // Set initial values
        og1[0] = 0; // First possibility starts with 0
        og2[0] = 1; // Second possibility starts with 1

        // Construct og1 and og2 based on derived array
        for (int i = 0; i < n - 1; ++i) {
            if (derived[i] == 0) {
                og1[i + 1] = og1[i]; // Same values
                og2[i + 1] = og2[i]; // Same values
            } else {
                og1[i + 1] = 1 - og1[i]; // Different values
                og2[i + 1] = 1 - og2[i]; // Different values
            }
        }

        // Check cyclic condition for both og1 and og2
        if ((og1[n - 1] ^ og1[0]) == derived[n - 1] || 
            (og2[n - 1] ^ og2[0]) == derived[n - 1]) {
            return true; // At least one valid array found
        }

        return false;
    }
};