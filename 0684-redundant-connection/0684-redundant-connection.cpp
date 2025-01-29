class Solution {
public:
    // Main function to find redundant connection
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        vector<vector<int>> adj(n + 1); // Use n+1 since nodes are 1-indexed
        
        for(auto elem : edges) {
            int n1 = elem[0] - 1; // Convert to 0-based indexing for DFS
            int n2 = elem[1] - 1;
            
            if(iscycle(adj, n1, n2)) {
                ans = elem;
            }
            
            // Add edges to adjacency list (using 1-based indexing)
            adj[elem[0]].push_back(elem[1]);
            adj[elem[1]].push_back(elem[0]);
        }
        
        return ans;
    }
    
private:
    // Helper function to check if adding edge (src, dest) creates a cycle
    bool iscycle(vector<vector<int>>& adj, int src, int dest) {
        // If no edges exist yet, no cycle possible
        if(adj[src + 1].empty() || adj[dest + 1].empty()) 
            return false;
            
        vector<bool> visited(adj.size(), false);
        return dfs(adj, src + 1, dest + 1, visited, -1);
    }
    
    // DFS function to detect cycle
    bool dfs(vector<vector<int>>& adj, int curr, int dest, vector<bool>& visited, int parent) {
        // If current node is destination, we found a path
        if(curr == dest) 
            return true;
            
        visited[curr] = true;
        
        // Check all neighbors
        for(int neighbor : adj[curr]) {
            if(neighbor == parent) // Skip parent node
                continue;
                
            if(!visited[neighbor]) {
                if(dfs(adj, neighbor, dest, visited, curr))
                    return true;
            }
        }
        
        return false;
    }
};