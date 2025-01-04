class Solution {
public:
    int countPalindromicSubsequence(string s) {

         vector<int> left(26, -1);   // Stores the first occurrence index of each character
        vector<int> right(26, -1);  // Stores the last occurrence index of each character
        set<pair<char, char>> st;   // Stores unique pairs of (start, middle character)

        // Fill the left and right vectors with the positions of characters
        for (int i = 0; i < s.size(); i++) {
            if (left[s[i] - 'a'] == -1) left[s[i] - 'a'] = i;
            right[s[i] - 'a'] = i;
        }

        // Loop through all characters 'a' to 'z'
        for (int c = 0; c < 26; c++) {
            if (left[c] != -1 && right[c] != -1 && left[c] < right[c]) {
                // If there is a valid range between the leftmost and rightmost positions
                for (int i = left[c] + 1; i < right[c]; i++) {
                    // Insert the pair (start, middle) character into the set
                    st.insert({s[left[c]], s[i]});
                }
            }
        }

        return st.size();
    }
};