class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

            int n = recipes.size();
            unordered_map<string,vector<int>>adj;
            unordered_map<string,int>mp;
            vector<int>indegree(n,0);

            for(auto elem : supplies)
            {
                mp[elem]++;
            }


            for(int i =0 ;i< n ;i++)
            {
                for(auto elem : ingredients[i])
                {
                    if(mp.find(elem) == mp.end())
                    {
                        adj[elem].push_back(i);
                        indegree[i]++;
                    }
                }

            }



            vector<string>ans;
            queue<int>q;


            for(int i =0 ;i< n ; i++)
            {
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }


            while(!q.empty())
            {
                int n = q.size();

                while(n--)
                {
                    int topi = q.front();
                    q.pop();
                    string ind = recipes[topi];
                    ans.push_back(ind);
                    for(auto nbr : adj[ind])
                    {
                        indegree[nbr]--;
                        if(indegree[nbr] == 0)
                        {
                            q.push(nbr);
                        }
                    }
                }
            }

        
        return ans;

    }
};