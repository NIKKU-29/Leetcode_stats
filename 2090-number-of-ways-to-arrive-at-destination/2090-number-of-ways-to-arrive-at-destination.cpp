class Solution {
public:

    const int MOD = 1e9 + 7;

  int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n);
        //adj list of each node with pair having neighbourt and time taken to reach

        for(auto elem : roads)
        {
            int x = elem[0];
            int y = elem[1];
            int w = elem[2];

            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        unordered_map<int,long long> ways;

        
        pq.push({0,0});
        dist[0]=0;
        ways[0]++;
  
        while(!pq.empty())
        {
            
                auto topi = pq.top();
                long long distance = topi.first;
                int nbr = topi.second;
                pq.pop();

                if(distance > dist[nbr]) continue;

                for(auto elem : adj[nbr])
                {
                    long long newDist = elem.second;
                    int newnbr = elem.first;

                    if(newDist + distance < dist[newnbr])
                    {
                        dist[newnbr] = newDist + distance;
                        ways[newnbr] = ways[nbr];
                        pq.push({newDist + distance , newnbr});
                    }
                    else if(newDist + distance == dist[newnbr])
                    {
                        ways[newnbr] = (ways[newnbr] + ways[nbr]) % MOD;

                    }
                }
            
        }

        return ways[n - 1];
        
    }
};