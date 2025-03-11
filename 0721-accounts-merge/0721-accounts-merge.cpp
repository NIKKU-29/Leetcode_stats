class DisjointSet{

        vector<int>parent,rank;

 public:

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i =0 ;i<= n ;i++)
        {
            parent[i]=i;
        }
    }

    int Pfind(int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = Pfind(parent[x]);
    }

    void UnionByRank(int u , int v)
    {
        int X_P = Pfind(u);
        int Y_P = Pfind(v);

        if(X_P != Y_P)
        {
            if(rank[X_P] > rank[Y_P])
            {
                parent[Y_P] = X_P;
            }

            else if(rank[X_P] < rank[Y_P])
            {
                parent[X_P] = Y_P;
            }

            else{
                    parent[Y_P] = X_P;
                    rank[X_P]++;
            }
        }
    }
};
    

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n =accounts.size();
        unordered_map<string,int>StringtoIdx;
        DisjointSet ds(n);

        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 1 ;j< accounts[i].size() ;j++)
            {   
                string mail = accounts[i][j];

                if(StringtoIdx.find(mail) == StringtoIdx.end())
                {
                    StringtoIdx[mail] = i;
                }

                else{
                    ds.UnionByRank(i , StringtoIdx[mail]); //link the two if not equal
                }
            }
        }


        vector<vector<string>>MergedMails(n);

        for(auto elem : StringtoIdx)
        {
             string mail = elem.first;
             int node = ds.Pfind(elem.second);
             MergedMails[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i =0 ;i < n ;i++)
        {
            if(MergedMails[i].size() == 0) continue;
            else{

                sort(MergedMails[i].begin(),MergedMails[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(auto elem : MergedMails[i])
                {
                    temp.push_back(elem);
                }
                 ans.push_back(temp);
            }

        }

        return ans;
    }
};