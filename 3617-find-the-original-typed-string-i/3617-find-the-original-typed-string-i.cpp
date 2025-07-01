class Solution {
public:
    int possibleStringCount(string word) {

        int count = 1;
        int n = word.size();

        for(int i = 0 ; i < n ; i++)
        {
            if(word[i] == word[i+1])
            {
                count++;
            }
        }

        return count;
        
    }
};