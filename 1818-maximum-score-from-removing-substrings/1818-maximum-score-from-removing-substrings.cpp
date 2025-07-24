class Solution 
{
public:
    int maximumGain(string s, int x, int y) {
        // Step 1: Remove higher-value substring first
        if (x < y)
        {
            return remove(s, 'b', 'a', y, x); // remove "ba" first
        }
        else
        {
            return remove(s, 'a', 'b', x, y); // remove "ab" first
        }
    }

private:
    int remove(string& s, char first, char second, int firstPoints, int secondPoints) 
    {
        int score = 0;
        vector<char> stack;

        // Step 2: First pass - remove the higher-value substring
        for (char c : s) 
        {
            if (!stack.empty() && stack.back() == first && c == second) 
            {
                stack.pop_back();
                score += firstPoints;
            } 
            else 
            {
                stack.push_back(c);
            }
        }

        // Step 3: Second pass - remove the lower-value substring from remaining string
        vector<char> stack2;
        for (char c : stack) 
        {
            if (!stack2.empty() && stack2.back() == second && c == first) 
            {
                stack2.pop_back();
                score += secondPoints;
            } 
            else 
            {
                stack2.push_back(c);
            }
        }

        // Step 4: Return total score
        return score;
    }
};