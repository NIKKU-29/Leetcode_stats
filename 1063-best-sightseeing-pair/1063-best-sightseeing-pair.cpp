class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxAdded = values[0];  // Keep track of the maximum (values[i] + i) seen so far
        int maxScore = INT_MIN;   // Initialize the maximum score
        
        for (int j = 1; j < n; ++j) {
            // Update the maximum score using the current `j`
            maxScore = max(maxScore, maxAdded + values[j] - j);
            
            // Update maxAdded for the next iteration
            maxAdded = max(maxAdded, values[j] + j);
        }
        
        return maxScore;
    }
};
