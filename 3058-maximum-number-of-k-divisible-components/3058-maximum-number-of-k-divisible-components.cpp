class Solution {
public:


    long long dfs(int current, int parent, vector<int> adjList[],
            vector<int> &values, int k, int &count)
            {
                long long sum=0;

                for(auto elem : adjList[current])
                {
                    if(elem != parent)
                    {
                        sum+=dfs(elem,current,adjList,values,k,count);
                    }
                }


                /* reached the leaf node */ 
                /* add the leat node value*/

                sum+=values[current];

                /*Check if this value is divisible by k*/ 
                /* if divisible then increase count*/

                if(sum%k==0)
                {
                    count++;

                    //this node is contributing itself alone not a part of other pairs of nodes 
                    //henece return 0

                    return 0;
                }

                return sum;

            }


    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        int count=0;

        dfs(0,-1,adjList,values,k,count);

        return count;
        
    }
};