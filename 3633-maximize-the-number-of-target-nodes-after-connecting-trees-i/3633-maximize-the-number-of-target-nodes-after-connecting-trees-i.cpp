class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    
        auto graph1 = buildGraph(edges1);
        auto graph2 = buildGraph(edges2);
        
       
        vector<int> result(graph1.size(), 0);
        
        
        vector<int> reachable1(graph1.size(), 0);
        vector<int> reachable2(graph2.size(), 0);
        
        for (int node = 0; node < graph1.size(); ++node) {  //upto k
            reachable1[node] = countNodesWithinDistance(graph1, node, k);
        }
        for (int node = 0; node < graph2.size(); ++node) { // up to k-1
            reachable2[node] = countNodesWithinDistance(graph2, node, k - 1);
        }
        

        for (int node1 = 0; node1 < graph1.size(); ++node1) {
            int maxTargets = 0;
            for (int node2 = 0; node2 < graph2.size(); ++node2) {
                maxTargets = max(maxTargets, reachable1[node1] + reachable2[node2]);
            }
            result[node1] = maxTargets;
            
            //cout<<result[node1]<<" ";
        }
        
        return result;
    }

    
    unordered_map<int, vector<int>> buildGraph(const vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    
    
    int countNodesWithinDistance(const unordered_map<int, vector<int>>& graph, int start, int maxDistance) {
        vector<int> visited(graph.size(), 0);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = 1;
        int count = 0;
        
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            
            if (dist > maxDistance) continue; ///skip
            count++;
            
            for (int neighbor : graph.at(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        
        return count;
    }
};
