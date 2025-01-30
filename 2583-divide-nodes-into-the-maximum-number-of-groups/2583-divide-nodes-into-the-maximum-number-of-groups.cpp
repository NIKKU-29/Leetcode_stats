class Solution {
public:

    int calculate(int node,vector<int>&levels,vector<bool>&visit,vector<vector<int>>&adj)
    {
        int currmax=levels[node];
        visit[node]=true;

        for(auto elem: adj[node])
        {   
            if(visit[elem]) continue;
            currmax=max(currmax,calculate(elem,levels,visit,adj));
            visit[elem]=true;
        }


        return currmax;
             
    }

    int bfs(int startnode,vector<vector<int>>&adj,int n)
    {
        queue<int>q;
        q.push(startnode);
        vector<bool>visited(n+1,false);
        visited[startnode]=true;
        int level=1;

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                 int curr=q.front();
                 q.pop();

                for(auto elem : adj[curr])
                {
                    if(visited[elem]) continue;

                    visited[elem]=true;
                    q.push(elem);
                }
            }

            level++;
        }

        return level-1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n+1);
        for(auto elem : edges)
        {
            int u=elem[0];
            int v=elem[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 245 , 136 , 2 , 16 , 1 , 24 <-adj
        
        int t=adj.size();
        vector<int>color(n+1,-1);

        for(int i=0 ;i<= n ;i++)
        {
            if(color[i]!=-1) continue;
            
            stack<int>st;
            st.push(i);
            color[i]=0;

            while(!st.empty())
            {
                int node=st.top();
                st.pop();
                
                for(auto elem : adj[node])
                {
                    if(color[elem]==-1)
                    {
                        color[elem]=1-color[node];
                        st.push(elem);
                    }

                    else if(color[node]==color[elem])
                    {
                        return -1;
                    }
                }
            }
        }
        
        //bfs
        
        vector<int>levels(n+1,0);
        for(int node=1 ; node <= n ;node++)
        {
            levels[node]=bfs(node,adj,n);
        }

        int maxeach=0;
        vector<bool>visit(n+1,false);
        for(int i=1 ;i <= n ;i++)
        {
            if(!visit[i])
            {
                maxeach+=calculate(i,levels,visit,adj);
            }
        }
       
       return maxeach;
        
    }
};