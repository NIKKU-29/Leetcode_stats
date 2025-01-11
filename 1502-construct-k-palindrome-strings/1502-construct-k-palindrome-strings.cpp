class Solution {
public:
    bool canConstruct(string s, int k) {
        
        unordered_map<char,int>mp;

        for(auto elem : s)
        {
            mp[elem]++;
        }

        // if(mp.size() < k) return false;

        int oc=0;
        int sum=0;

        for(auto elem : mp)
        {
            if(elem.second%2==1)
            {
                elem.second--;
                k--;
            }
            sum+=elem.second;
        }

        if(oc > k) return false;
        else if (sum>=k)return true;

            


        return false;

    }
};