class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if (n % 2 != 0) return -1;  // There must be an even number of players
        
        unordered_map<int, int> mp;
        long long Total = 0;

        // Calculate the total skill sum and store frequency of each skill level
        for (int i = 0; i < n; i++) {
            mp[skill[i]]++;
            Total += skill[i];
        }

        // Calculate the target sum for each pair
        int paircount = n / 2;
        int Target = Total / paircount;

        long long ans = 0;
        
        // Form the pairs
        for (int i = 0; i < n; i++) {
            int currSkill = skill[i];
            if (mp[currSkill] <= 0) continue;  // Skip already paired players

            int Aim = Target - currSkill;
            if (mp.find(Aim) != mp.end() && mp[Aim] > 0) {
                // Add the product of the pair
                ans += currSkill * Aim;
                // Decrement the frequencies of both elements
                mp[currSkill]--;
                mp[Aim]--;
            } else {
                // Pairing is not possible
                return -1;
            }
        }

        return ans;
    }
};
