class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0 ;i< n ;i++)
        {
            if(color[i]!=-1) continue;

            stack<int>st;
            st.push(i);
            color[i]=0;

            while(!st.empty())
            {
                int node=st.top();
                st.pop();
                
                for(auto elem : graph[node])
                {
                    if(color[elem]==-1)
                    {
                        color[elem]=1-color[node];
                        st.push(elem);
                    }

                    else if(color[node]==color[elem])
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};