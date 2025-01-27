class Solution {
public:


    void dfs(int course,int start,vector<vector<int>>& adj,vector<vector<bool>>&isprerequisite)
    {
            for(auto pre : adj[course])
            {
                if(!isprerequisite[start][pre])
                {
                    isprerequisite[start][pre]=true;
                    dfs(pre,start,adj,isprerequisite);
                }
            }
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n=queries.size();

        if(prerequisites.empty())
        {
            return vector<bool>(n,false);
        }

        vector<vector<bool>>isprerequisite(numCourses,vector<bool>(numCourses,false));
        vector<vector<int>> adj(numCourses);


        for(auto elem : prerequisites)
        {
            //we would make the graph opposite for transversal;

            int pre=elem[0];
            int cor=elem[1];

            adj[cor].push_back(pre);
        }

        //now transversal

        for(int i=0 ;i<numCourses ; i++)
        {
            dfs(i,i,adj,isprerequisite);
        }

        vector<bool>ans;

        for(auto elem : queries)
        {
            int pre=elem[0];
            int course=elem[1];

            if(isprerequisite[course][pre]) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
        
    }
};