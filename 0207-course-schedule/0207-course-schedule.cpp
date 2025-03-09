class Solution {
public:

    bool solver(int numCourses,vector<vector<int>>&adj,vector<int>&indegree)
    {
        queue<int>q;
        int count =0;

        for(int i=0 ;i< numCourses ;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        while(!q.empty())
        {
            int size = q.size();

            int top = q.front();
            q.pop();
                
                for(auto& elem : adj[top])
                {
                    indegree[elem]--;

                    if(indegree[elem] == 0)
                    {
                        q.push(elem);
                        count++;
                    }
                }

            
        }

        return count == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n);

        for(auto elem : prerequisites)
        {
            int u = elem[0];
            int v = elem[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        return solver(numCourses,adj,indegree);

    }
};