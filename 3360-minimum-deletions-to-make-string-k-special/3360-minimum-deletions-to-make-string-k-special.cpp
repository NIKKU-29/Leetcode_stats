class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }

        vector<int> counts;
        for (int f : freq) {
            if (f > 0) counts.push_back(f);
        }

        sort(counts.begin(), counts.end());

        int minDel = INT_MAX;

        for (int i = 0; i < counts.size(); ++i) {
            int target = counts[i];
            int del = 0;

            for (int j = 0; j < counts.size(); ++j) {
                if (counts[j] < target) {
                    del += counts[j];  // remove all
                } else if (counts[j] > target + k) {
                    del += counts[j] - (target + k);  // reduce to target + k
                }
            }

            minDel = min(minDel, del);
        }

        return minDel;
    }
};
