class Solution {
public:


    int bfs(int currnode,unordered_map<int,vector<int>>&adj,vector<bool>&visited)
    {
            int maxlength=0;
            queue<pair<int,int>>q;
            q.push({currnode,0});

            while(!q.empty())
            {
                auto[node,len] = q.front();
                q.pop();

                for(auto elem : adj[node])
                {
                    if(!visited[elem])
                    {
                        visited[elem]=true;
                        q.push({elem,len+1});
                        maxlength=max(maxlength,len+1);
                    }
                }
            }

            return maxlength;

    }

    int maximumInvitations(vector<int>& favorite) {
        
        int n=favorite.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0 ;i<n ;i++)
        {
            adj[favorite[i]].push_back(i);
        }

        int cycle_2_length=0;
        int max_length_cycle=0;

        vector<bool>visited(n,false);

        for(int i=0 ;i< n ;i++)
        {
            int currnode=i;

            if(!visited[currnode])
            {
                
                unordered_map<int,int>mp;
                int nodecount=0;

                while(!visited[currnode])
                {
                    visited[currnode]=true;
                    mp[currnode]=nodecount;

                    int nextnode=favorite[currnode];
                    nodecount++;

                    if(mp.count(nextnode)) 
                    {
                        int current_cycle_length=nodecount-mp[nextnode];

                        if(current_cycle_length!=2)
                        {
                            max_length_cycle=max(max_length_cycle,current_cycle_length);
                        }

                        if(current_cycle_length == 2)
                        {
                            vector<bool>visitedNodes(n,false);
                            visitedNodes[currnode]=true;
                            visitedNodes[nextnode]=true;
                            cycle_2_length+= 2 + bfs(currnode,adj,visitedNodes) + bfs(nextnode,adj,visitedNodes);
                        }

                        break;
                    }

                    
                    currnode=nextnode;
                    
                }
            }
        }

        return max(cycle_2_length,max_length_cycle);
        
    }
};