class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        vector<unordered_set<int>> children(n);
        vector<int> xor_val = nums;
        vector<int> degree(n, 0);

        // Build the graph
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int total_xor = 0;
        queue<int> q;
        vector<bool> seen(n, false);

        // Calculate total XOR and prepare leaves for processing
        for (int i = 0; i < n; ++i) {
            total_xor ^= nums[i];
            if (degree[i] == 1) {
                q.push(i);
                seen[i] = true;
            }
        }

        // Build the tree (bottom-up), track children and XOR values
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                if (!seen[next]) {
                    children[next].insert(cur);
                    children[next].insert(children[cur].begin(), children[cur].end());
                    xor_val[next] ^= xor_val[cur];
                }

                degree[next]--;
                if (degree[next] == 1 && !seen[next]) {
                    seen[next] = true;
                    q.push(next);
                }
            }
        }

        int res = INT_MAX;

        // Try removing two edges and calculate XOR partitions
        for (int i = 0; i < edges.size() - 1; ++i) {
            for (int j = i + 1; j < edges.size(); ++j) {
                int a = edges[i][0], b = edges[i][1];
                if (children[a].count(b)) swap(a, b);

                int c = edges[j][0], d = edges[j][1];
                if (children[c].count(d)) swap(c, d);

                vector<int> parts;

                if (children[a].count(c)) {
                    // c is inside a's subtree
                    parts = {xor_val[c], xor_val[a] ^ xor_val[c], total_xor ^ xor_val[a]};
                } else if (children[c].count(a)) {
                    // a is inside c's subtree
                    parts = {xor_val[a], xor_val[c] ^ xor_val[a], total_xor ^ xor_val[c]};
                } else {
                    // a and c are in different subtrees
                    parts = {xor_val[a], xor_val[c], total_xor ^ xor_val[a] ^ xor_val[c]};
                }

                int max_xor = *max_element(parts.begin(), parts.end());
                int min_xor = *min_element(parts.begin(), parts.end());
                res = min(res, max_xor - min_xor);
            }
        }

        return res;
    }
};
