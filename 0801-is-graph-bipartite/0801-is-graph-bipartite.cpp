class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1: unvisited, 0 & 1: two partitions

        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue; // Already colored, skip

            stack<int> s;
            s.push(i);
            color[i] = 0; // Start coloring the first component

            while (!s.empty()) {
                int node = s.top();
                s.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node]; // Alternate colors
                        s.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Conflict detected
                    }
                }
            }
        }
        return true; // No conflicts found
    }
};
