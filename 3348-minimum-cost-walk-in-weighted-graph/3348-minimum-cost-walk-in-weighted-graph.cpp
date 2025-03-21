class Disjoint {
    vector<int> parent, rank, cost;

public:
    Disjoint(int n, vector<int>& InitialCost) {
        rank.resize(n, 0);
        parent.resize(n);
        cost = InitialCost;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path Compression
        }
        return parent[x];
    }

    void Union(int x, int y, int w) {
        int parent_x = find(x);
        int parent_y = find(y);


        if (parent_x == parent_y) {
            cost[parent_x] &= w;  
            return;
        }

        else{

        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
            cost[parent_x] &= cost[parent_y];
            cost[parent_x] &=w;  // Apply AND operation
        } 
        else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
            cost[parent_y] &= cost[parent_x];
            cost[parent_y] &=w;  
        } 
        else {
            parent[parent_x] = parent_y;
            cost[parent_y] &= cost[parent_x];
            cost[parent_y] &=w;  
            rank[parent_y]++;
        }
    }
        

    }

    int getcost(int x) {
        return cost[find(x)];  // Get cost of representative
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> InitialCost(n, INT_MAX);  // Use INT_MAX for bitwise AND operations

        Disjoint ds(n, InitialCost);

        for (auto& elem : edges) {
            int x = elem[0];
            int y = elem[1];
            int w = elem[2];

            ds.Union(x, y, w);
        }

        vector<int> ans;

        for (auto& q : query) {
            int x = q[0];
            int y = q[1];


            int parent_x = ds.find(x);
            int parent_y = ds.find(y);


            if(x == y) ans.push_back(0);

            else if ( parent_x != parent_y) {
                ans.push_back(-1);
            } 

            else {
                int cost = ds.getcost(parent_x);
                ans.push_back(cost);
            }
        }

        return ans;
    }
};