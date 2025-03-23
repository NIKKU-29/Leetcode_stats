class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else { 
                parent[rootB] = rootA;
                rank[rootA]++; // Increase rank if both have the same rank
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);
        vector<int> degree(n, 0);  // Store the degree of each node

        // Initialize DSU
        for (int i = 0; i < n; i++) parent[i] = i;

        // Process edges
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            unionSets(u, v);
            degree[u]++;
            degree[v]++;
        }

        // Count complete components
        unordered_map<int, int> componentSize, edgeCount;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            componentSize[root]++;      // Count number of nodes in the component
            edgeCount[root] += degree[i]; // Sum up degrees
        }

        int count = 0;
        for (auto& [root, nodes] : componentSize) {
            int totalEdges = edgeCount[root] / 2;  // Each edge is counted twice
            if (totalEdges == (nodes * (nodes - 1)) / 2) {
                count++; // It forms a complete graph (clique)
            }
        }

        return count;
    }
};
