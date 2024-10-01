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

         unordered_map<char, string> mp; // Map for digit to corresponding letters
        vector<string> ans;

        // If digits is empty, return an empty vector
        if (digits.empty()) return {};

        // Initialize the mapping for the digits to letters
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(digits,mp,0,"",ans);

        return ans;
    }
};