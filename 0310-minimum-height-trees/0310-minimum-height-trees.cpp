class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         
         vector<int> indegree(n, 0);
         vector<vector<int>>adj(n);
        
        if(n == 1) return {0};

         queue<int>q;

         for(auto elem : edges)
         {
            int u = elem[0];
            int v = elem[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

         for(int i=0 ;i<indegree.size();i++)
         {
            if(indegree[i] == 1) q.push(i);
         }

         while(n > 2)
         {
            int siz = q.size();
            n-=siz;

            while(siz--)
            {
                int u = q.front();
                q.pop();
                
                for(auto& v : adj[u])
                {
                    indegree[v]--;
                    if(indegree[v] == 1)
                    {
                        q.push(v);
                    }
                }

            }
         }

         vector<int>ans;

         while(!q.empty())
         {
            ans.push_back(q.front());
            q.pop();
         }

        return ans;
    }
};