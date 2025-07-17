class Solution {
public:

    class DSU {
    vector<int> parent, rank;
    public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

    
    int minTime(int n, vector<vector<int>>& edges, int k) {

        if(k <= 1) return 0;

        int m = edges.size();
        int maxt = 0;

        for(auto elem : edges)
            {
                maxt = max(maxt,elem[2]);
            }

        sort(edges.begin(),edges.end(),[&] (auto &a,auto &b){
            return a[2] < b[2];
        }); //custom

        auto check = [&](int t)
        {
            DSU dsu(n);
            int comps = n;

            for(int i = edges.size() -1 ; i >= 0 && edges[i][2] > t ; --i)
                {
                    if(dsu.unite(edges[i][0],edges[i][1])) comps--;
                    if(comps < k) return false;
                }
            
            return comps >= k;
        };


        if(check(0)) return 0;


        int l = 1 , h = maxt , ans = maxt;

        while(l <= h)
            {
                int mid = l + (h - l)/2;
                if(check(mid))
                {
                    ans = mid;
                    h = mid -1;
                }

                else l = mid + 1;
            }

        return ans;
    }
};