class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Find Bob's path to root (node 0)
        vector<int> bobTime(n, n); // Initialize with a value larger than any possible time
        
        // Find Bob's path
        function<bool(int, int, int)> findBobPath = [&](int node, int par, int time) {
            if (node == 0) {
                bobTime[node] = time;
                return true;
            }
            
            for (int child : adj[node]) {
                if (child != par) {
                    if (findBobPath(child, node, time + 1)) {
                        bobTime[node] = time;
                        return true;
                    }
                }
            }
            
            return false;
        };
        
        findBobPath(bob, -1, 0);
        
        // DFS to find max path sum for Alice
        int maxSum = INT_MIN;
        function<void(int, int, int, int)> findMaxPath = [&](int node, int par, int time, int sum) {
            // Calculate Alice's amount at this node
            int currentAmount = 0;
            if (time < bobTime[node]) {
                currentAmount = amount[node];
            } else if (time == bobTime[node]) {
                currentAmount = amount[node] / 2;
            }
            
            sum += currentAmount;
            
            // Check if it's a leaf node (other than root)
            bool isLeaf = true;
            for (int child : adj[node]) {
                if (child != par) {
                    isLeaf = false;
                    findMaxPath(child, node, time + 1, sum);
                }
            }
            
            if (isLeaf && node != 0) {
                maxSum = max(maxSum, sum);
            }
        };
        
        findMaxPath(0, -1, 0, 0);
        return maxSum;
    }
};