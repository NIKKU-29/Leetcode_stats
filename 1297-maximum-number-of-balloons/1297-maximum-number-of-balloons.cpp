class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int>mp;

        for(auto elem : text)
        {
            mp[elem]++;
        }

        mp['l']/=2;
        mp['o']/=2;

        vector<char>vec={'b','a','l','o','n'};

        int ans = INT_MAX;

        for(auto elem : vec)
        {
            ans= min(ans,mp[elem]);
        }

        return ans;

    }
};