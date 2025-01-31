class Solution {
public:
    vector<int> dp;

    bool solver(int idx, string& s, unordered_set<string>& container, unordered_set<int>& wordLengths) {
        if (idx == s.size()) {
            return true;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Try substrings of lengths that are in the wordLengths set
        for (int len : wordLengths) {
            if (idx + len <= s.size()) {
                string curr = s.substr(idx, len);
                if (container.count(curr) && solver(idx + len, s, container, wordLengths)) {
                    return dp[idx] = 1;
                }
            }
        }

        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);  // Initialize with -1 (uncomputed)
        unordered_set<string> container(wordDict.begin(), wordDict.end());
        
        // Store the lengths of words in the dictionary
        unordered_set<int> wordLengths;
        for (const string& word : wordDict) {
            wordLengths.insert(word.size());
        }

        return solver(0, s, container, wordLengths);
    }
};
