class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 0, count = 0, n = colors.size();

        for (int j = 0; j < n + k - 1; j++) {
            if (j > 0 && colors[j % n] == colors[(j - 1) % n]) {
                i = j;  // Reset window start if non-alternating pattern is found
            }
            
            if (j - i + 1 == k) {  // Check if the window size is exactly k
                count++;
                i++;  // Move start of the window forward to maintain size
            }
        }

        return count;
    }
};
