class Solution {
public:
    int ans=INT_MIN;

    bool Timefinder(int bob,int currtime,vector<bool>&visited,vector<vector<int>>&adj,vector<int>&timingBob)
    {
        if(bob == 0)
        {
            timingBob[bob]=currtime;
            return true;
        }

        for(auto neighbour : adj[bob])
        {
            if(!visited[neighbour])
            {
                
                visited[neighbour]=true;
                if(Timefinder(neighbour,currtime + 1,visited,adj,timingBob))
                {
                    timingBob[bob]=currtime;
                    return true;
                }
                visited[neighbour]=false; //unmark if this donot contibute to teh path to the 0
            }
        }

        return false;
    }

    void solver(int alice ,int timenow , int alicesum ,vector<vector<int>>&adj,vector<int>&amount,vector<int>&timingBob,vector<bool>&visited)
    {
      
        if(timingBob[alice] == -1) //bob didnt visited this path
        {
            alicesum+=amount[alice];
        }

        else if(timingBob[alice] > timenow)
        {
            alicesum+=amount[alice]; //bob reaches here after alice
        }

        if(timingBob[alice] == timenow)
        {
            alicesum+=(amount[alice]/2); //reach together devide in half
        }

        

        if (adj[alice].size() == 1 && alice != 0) {  //node reaching condition
            ans = max(ans, alicesum); 
            return;
        }

         for (int neighbor : adj[alice]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                solver(neighbor, timenow + 1, alicesum, adj, amount, timingBob, visited);
                visited[neighbor] = false; // Backtrack
            }
        }
        
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

            int n=amount.size();
            vector<vector<int>>adj(n);
            vector<bool>visited(n,false);


            for(auto elem : edges)
            {
                int a=elem[0];
                int b=elem[1];

                adj[a].push_back(b);
                adj[b].push_back(a);
            }

            vector<int>timingBob(n,-1); //stores the time at which box is at the specific node

            visited[bob]=true;
            Timefinder(bob,0,visited,adj,timingBob);

            int alicesum=0;
            int timenow=0;

            visited.assign(n, false); // Reset visited array
            visited[0] = true;
            solver(0,timenow,alicesum,adj,amount,timingBob,visited);

            return ans;

    }
};