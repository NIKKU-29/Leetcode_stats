class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int ans = INT_MAX;

        unordered_map<char,int>mp;
        for(auto elem : text) mp[elem]++; 
        int b = mp['b'];
        int a = mp['a'];
        int n = mp['n'];
        int l = (mp['l']/2);
        int o = (mp['o']/2);
        
        ans = min({b,a,l,o,n});
        

        return ans;
        
    }
};