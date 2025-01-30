class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> st1, st2; // Two sets for bipartite checking
        vector<bool> visited(n, false); // Track visited nodes
        
        for (int i = 0; i < n; i++) {  
            if (visited[i]) continue;  // Skip already visited nodes

            queue<int> q;
            q.push(i);
            st1.insert(i); // Start with the first set

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (st1.count(node)) { // If node is in st1, neighbor should be in st2
                        if (st1.count(neighbor)) return false; // Conflict detected
                        else {
                            st2.insert(neighbor);
                            q.push(neighbor);
                        }
                    } else { // If node is in st2, neighbor should be in st1
                        if (st2.count(neighbor)) return false; // Conflict detected
                        if (!st1.count(neighbor)) {
                            st1.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                visited[node] = true;
            }
        }
        return true; // No conflicts, graph is bipartite
    }
};
