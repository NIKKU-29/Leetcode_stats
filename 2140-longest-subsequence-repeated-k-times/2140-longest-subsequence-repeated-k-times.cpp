class Solution {
public:


    bool helper(string part, string t, int k) {
        int count = 0, i = 0;
        for (char ch : t) {
            if (ch == part[i]) {
                if (++i == part.size()) 
                {
                    i = 0;
                    if (++count == k) return true;
                }
            }
        }
            return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        
        string ans = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string curr = q.front(); 
            q.pop();
            
            for (char ch = 'a'; ch <= 'z'; ++ch) 
            {
                string sub = curr + ch;
                if (helper(sub, s, k)) 
                {
                    ans = sub;
                    q.push(sub);
                }
            }
        }
        return ans;
    }
};