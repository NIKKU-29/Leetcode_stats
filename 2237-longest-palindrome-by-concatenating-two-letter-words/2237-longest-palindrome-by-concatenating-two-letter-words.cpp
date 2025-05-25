class Solution {
public:

    bool ispalind(string s) {
        return s[0] == s[1]; // Shortcut for 2-letter words
    }

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, int> selfpalindrom;
        int count = 0;

        // Separate palindromes and others
        for (auto& word : words) {
            if (ispalind(word)) {
                selfpalindrom[word]++;
            } else {
                mp[word]++;
            }
        }

        // Count pairs like "ab" and "ba"
        for (auto& [curr, freq] : mp) {
            string rev = curr;
            reverse(rev.begin(), rev.end());

            if (mp.find(rev) != mp.end()) {
                int pairs = min(freq, mp[rev]);
                count += pairs * 4;

                mp[rev] = 0; // Avoid recounting
                mp[curr] = 0;
            }
        }

        // Handle self-palindromic words like "gg", "aa", etc.
        bool midAdded = false;
        for (auto& [pal, freq] : selfpalindrom) {
            count += (freq / 2) * 4; // pairs of palindromes
            if (freq % 2 == 1 && !midAdded) {
                count += 2; // One can go in the middle
                midAdded = true;
            }
        }

        return count;
    }
};
