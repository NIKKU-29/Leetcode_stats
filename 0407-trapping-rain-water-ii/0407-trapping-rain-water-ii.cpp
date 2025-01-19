class Solution {
public:

    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    typedef pair<int,pair<int,int>>p;
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m=heightMap.size();
        int n=heightMap[0].size();

        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        //push boundaries i pq top horizontal
        for(int j=0 ; j< n ;j++)
        {
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[m-1][j],{m-1,j}});
            visited[0][j]=true;
            visited[m-1][j]=true;
        }

        for(int i=0 ;i<m ;i++ )
        {
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            visited[i][0]=true;
            visited[i][n-1]=true;
        } 

        int water=0;


        while(!pq.empty())
        {
            p curr=pq.top();
            pq.pop();
            int H=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;

            for(auto elem : directions)
            {
                int newi=i+elem[0];
                int newj=j+elem[1];

                if(newi >= 0 && newi < m && newj>=0 && newj < n && !visited[newi][newj])
                {
                    water+=max((H - heightMap[newi][newj]),0);
                    int newH=max(H,heightMap[newi][newj]);
                    pq.push({newH,{newi,newj}});
                    visited[newi][newj]=true;
                }
            }

        }
        return water;
        
    }
};