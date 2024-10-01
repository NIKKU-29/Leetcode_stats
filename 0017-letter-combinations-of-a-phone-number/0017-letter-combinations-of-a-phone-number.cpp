class Solution {
public:

    void backtrack(string& digits,unordered_map<char,string>&mp,int index,string current,vector<string>&ans)
    {
        if(index==digits.size())
        {
            ans.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = mp[digit];


        for(char elem : letters)
        {
            backtrack(digits,mp,index+1,current + elem ,ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        char elem = 'a';
        vector<string> ans;

        if (digits.empty()) return {};

        for (char i = '2'; i <= '9'; i++) { // Start from '2' to '9'
            string s = ""; // Reset string for each digit
            int counter = 0;

            if (i == '7' || i == '9') { // 7 and 9 have 4 letters
                while (counter < 4) {
                    s += elem;
                    elem++;
                    counter++;
                }
            } else { // 2, 3, 4, 5, 6, 8 have 3 letters
                while (counter < 3) {
                    s += elem;
                    elem++;
                    counter++;
                }
            }

            mp[i] = s; // Store the corresponding letters for each digit
        }

        backtrack(digits, mp, 0, "", ans); // Start backtracking
        return ans; // Return the result
    }
};