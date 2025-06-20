class Solution {
public:
    int maxDistance(string s, int k) {
        

        int x=0,y=0;
        int n = s.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            char elem = s[i];
            if(elem == 'E') x++;
            if(elem == 'W') x--;
            if(elem == 'N') y++;
            if(elem == 'S') y--;

            ans = max(ans,min(abs(x)+abs(y)+ k*2,i+1));
        }

        return ans;
    
    }
};