class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> pos_map;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pos_map[s[i]].push_back(i);
            } else {
                // Remove latest index of smallest available char
                for (auto& [ch, idxs] : pos_map) {
                    if (!idxs.empty()) {
                        idxs.pop_back();
                        break;
                    }
                }
            }
        }

        // Mark remaining indices
        unordered_set<int> keep;
        for (auto& [ch, idxs] : pos_map) {
            for (int i : idxs) keep.insert(i);
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (keep.count(i)) ans += s[i];
        }

        return ans;
    }
};
