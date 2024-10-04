class Solution {
public:
    
    typedef long long ll;

    ll dividePlayers(vector<int>& skill) {

        int n=skill.size();
        unordered_map<int,int>mp;
 
        int paircount=n/2;
        int Total=0;

        for(auto & elem : skill)
        {
            mp[elem]++;
            Total+=elem;
        }


        int Target=Total/paircount;
        ll ans=0;

        for(int i=0;i<n;i++)
        {
            if(mp[skill[i]] <= 0) continue;

            int Aim=Target-skill[i];
            if(mp.find(Aim)!=mp.end() && mp[Aim]>0)
            {
                ans+=Aim * skill[i];
                mp[skill[i]]--;
                mp[Aim]--;
            }else{
                return -1;
            }
        }

        return ans;

    }
};
