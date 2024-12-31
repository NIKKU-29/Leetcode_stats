class Solution {
public:
    int solve(int index, int n, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (index >= n) 
            return 0; // Base case: all days are covered
        
        if (dp[index] != -1) 
            return dp[index]; // Memoization check

        // Cost for 1-day pass
        int pass1 = costs[0] + solve(index + 1, n, days, costs, dp);

        // Cost for 7-day pass
        int jumper = index; // Initialize jumper to current index
        int maxdays = 7 + days[jumper]; // Calculate the last day covered by the 7-day pass
        while (jumper < n && days[jumper] < maxdays) {
            jumper++; // Move jumper to the next index if a specific pass is purchased
        }
        int pass7 = costs[1] + solve(jumper, n, days, costs, dp); // Note: jumper is used to jump to the next index if a 7-day pass is purchased

        // Cost for 30-day pass
        jumper = index; // Reinitialize jumper to current index
        maxdays = 30 + days[jumper]; // Calculate the last day covered by the 30-day pass
        while (jumper < n && days[jumper] < maxdays) {
            jumper++; // Move jumper to the next index if a specific pass is purchased
        }
        int pass30 = costs[2] + solve(jumper, n, days, costs, dp); // Note: jumper is used to jump to the next index if a 30-day pass is purchased

        // Memoize and return the minimum cost of the three options
        return dp[index] = min(pass1, min(pass7, pass30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(); // Correct the size calculation for n
        vector<int> dp(n, -1); // Initialize dp array with size n
        return solve(0, n, days, costs, dp);
    }
};
