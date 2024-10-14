#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Base case: if the input string is empty, return an empty vector.
        if(digits.empty()) return {};

        // Mapping of digits to letters.
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        // Vector to store the combinations.
        vector<string> ans;
        ans.push_back("");  // Start with an empty combination.

        // Iterate through each digit in the input string.
        for (char digit : digits) {
            string letters = mp[digit];  // Get the corresponding letters for the digit.
            vector<string> temp;  // Temporary vector to store new combinations.

            // Iterate through each combination formed so far.
            for (const string& combination : ans) {
                // Create new combinations by appending each letter to the current combination.
                for (char letter : letters) {
                    temp.push_back(combination + letter);
                }
            }

            // Update the ans with the new combinations formed for the current digit.
            ans = temp;
        }

        return ans;  // Return the final combinations.
    }
};
