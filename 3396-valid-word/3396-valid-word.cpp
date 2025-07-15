class Solution {
public:
    bool isValid(string word) {
        bool hasVowel = false, hasConsonant = false;
        int count = 0;

        for (char c : word) {
            if (!isalnum(c)) return false;  

            count++;

            if (isalpha(c)) {
                char upper = toupper(c);
                if (upper == 'A' || upper == 'E' || upper == 'I' || upper == 'O' || upper == 'U')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
        }

        return count >= 3 && hasVowel && hasConsonant;
    }
};
