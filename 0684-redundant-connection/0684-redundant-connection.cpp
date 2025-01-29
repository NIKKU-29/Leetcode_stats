class Solution {
public:

    bool dfs(int curr,int desti,vector<vector<int>>&adj,int parent,vector<bool>&visited)
    {
        if(curr==desti)
        {
            return true;
        }

        visited[curr]=true;

        for(auto elem : adj[curr])
        {
            if(elem==parent) continue;

            if(!visited[elem])
            {
                if(dfs(elem,desti,adj,curr,visited)) return true;
            }
        }

        return false;

    }

    bool iscycle(vector<vector<int>>&adj,int n1 ,int n2)
    {
        if(adj[n1].empty() || adj[n2].empty()) //node not prsent in graph
        {
            return false; 
        }
        
        vector<bool>visited(adj.size(),false);
        return dfs(n1,n2,adj,-1,visited);

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int>ans;
        int n=edges.size();
        vector<vector<int>>adj(n+1);


        for(auto elem : edges)
        {
            int n1=elem[0];
            int n2=elem[1];

            if(iscycle(adj,n1,n2)) //if it is possible to reach n2 using n1 neighbourse then cycle is prsent use dfs
            {
                ans=elem;
            }      

            adj[n1].push_back(n2);
            adj[n2].push_back(n1);       
        }

        return ans;

    }
};