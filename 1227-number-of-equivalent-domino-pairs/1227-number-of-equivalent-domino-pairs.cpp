class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int pairs = 0;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) swap(a, b);

            // Add existing count directly to the result
            pairs += mp[{a, b}]++;

            // This works because for each new identical domino,
            // it can pair with all previous ones of the same type
        }

        return pairs;
    }
};
