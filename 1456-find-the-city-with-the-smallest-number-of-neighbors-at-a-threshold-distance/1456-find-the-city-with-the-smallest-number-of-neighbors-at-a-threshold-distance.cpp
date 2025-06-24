class Solution {
public:

    int solver(int n,vector<vector<int>>& Min_dist, int limit)
    {
        int smallest=INT_MAX;
        int city=-1;

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {   
                if(i!=j && Min_dist[i][j]<=limit)
                {
                    count++;
                }
            }

            if(count<=smallest)
            {
                smallest=count;
                city=i;
            }
        }

        return city;
    }

    void Djk(int n,unordered_map<int,vector<pair<int,int>>>&adj, vector<vector<int>>&dist,int start){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,start});

        dist[start][start] = 0;

        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();

               for(auto& p : adj[node])
               {
                    int adjdistance=p.second;
                    int adjnode=p.first;
                

                if(distance + adjdistance < dist[start][adjnode])
                {
                    dist[start][adjnode] = distance + adjdistance;
                    pq.push({distance + adjdistance,adjnode});
                }


            }
         }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>>Min_dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++)
        {
            Min_dist[i][i]=0;
        }

        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto edge : edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        for(int i=0;i<n;i++)
        {
            Djk(n,adj,Min_dist,i);
       }


       return solver(n,Min_dist,distanceThreshold);
        
    }
};