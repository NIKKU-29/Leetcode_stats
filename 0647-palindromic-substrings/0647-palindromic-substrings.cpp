class Solution {
public:
    // Check if a given string is a palindrome.
    bool isPalindrome(const string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    // Recursive helper that builds the substring contiguously starting at 'start'
    // 'index' is the current end position for the substring.
    // 'curr' holds the current substring being built.
    // 's' is the input string.
    // 'count' is updated whenever a palindromic substring is found.
    void buildSubstring(int index, int start, const string &s, string &curr, int &count) {
        // Base case: if index has reached the end of the string, stop.
        if (index >= s.size()) {
            return;
        }
        
        // Append the current character at index.
        curr.push_back(s[index]);
        
        // Check if the current contiguous substring is a palindrome.
        if (isPalindrome(curr)) count++;
        
        // Continue extending the substring (contiguously).
        buildSubstring(index + 1, start, s, curr, count);
        
        
        
    }
    
    int countSubstrings(string s) {
        int count = 0;
        // For each possible starting index, build contiguous substrings.
        for (int i = 0; i < s.size(); i++) {
            string curr = "";
            buildSubstring(i, i, s, curr, count);
        }
        return count;
    }
};
