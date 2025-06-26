class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0;
        int len = 0;

        for (auto elem : s) {
            if (elem == '0') cnt++;
        }

        int n = s.size();
        int builder = 0;

        for (int i = 0; i < n; i++) {
            char last = s[n - 1 - i];

            if (last == '1') {
                if (i < 31 && builder + (1 << i) <= k) {
                    builder += (1 << i);
                    len++;
                } else {
                    return len + cnt;
                }
            } else {
                cnt--;
                len++;
            }
        }

        return len + cnt;
    }
};
