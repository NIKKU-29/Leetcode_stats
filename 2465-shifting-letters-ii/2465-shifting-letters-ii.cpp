class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n=s.size();
        vector<int>changes(n+1,0);


        for(auto elem : shifts)
        {
            int start=elem[0];
            int end=elem[1];
            int move=elem[2];

            changes[start] += (move == 1) ? 1 : -1;
            changes[end+1] -= (move == 1) ? 1 : -1;
        }
        
        int shift = 0;
        for(int j = 0; j < n; j++) {
            shift += changes[j];
            int Tshift = ((s[j] - 'a' + shift)%26 + 26) % 26;
            s[j] = 'a' + Tshift;
        }
        
        return s;

    }
};