class Solution {
public:

    int t[21][21];

    bool solve(int i, int j, string s, string p) {
        if (j == p.length() && i == s.length()) 
        {
            return true;
        }

        

        bool first_match = false;

        if(t[i][j]!=-1) return t[i][j];

        if (i < s.length() && (p[j] == s[i] || p[j] == '.')) {
            first_match = true;
        }

        if ( j+1 < p.length() && p[j + 1] == '*') {
            bool take = first_match && solve(i + 1, j, s, p);
            bool notake = solve(i, j + 2, s, p);

            return  t[i][j] = take || notake;
        }

        return  t[i][j]= first_match && solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) { 
        memset(t , -1, sizeof(t));
        return solve(0, 0, s, p); }
};