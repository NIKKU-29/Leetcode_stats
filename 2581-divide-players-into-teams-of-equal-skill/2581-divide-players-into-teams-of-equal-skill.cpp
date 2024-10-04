class Solution {
public:
    typedef long long ll;

    ll dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());  // Sort the skills in ascending order

        int paircount = n / 2;
        ll Total = accumulate(skill.begin(), skill.end(), 0LL);  // Sum of all skills

        // Check if total can be evenly divided
        if (Total % paircount != 0) {
            return -1;  // Early exit if pairing is impossible
        }

        int Target = Total / paircount;
        ll ans = 0;

        // Use two pointers to pair the players
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = skill[left] + skill[right];

            if (sum != Target) {
                return -1;  // If pairing is impossible
            }

            // Accumulate the product of pairs
            ans += (ll)skill[left] * skill[right];

            // Move pointers inward
            left++;
            right--;
        }

        return ans;
    }
};
