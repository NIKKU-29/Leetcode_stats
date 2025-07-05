class Solution {
public:
    string concatHex36(int n) {
        unordered_map<int,char>mp;

        for(int i = 0 ; i <= 9 ; i++) mp[i] = i + '0';
        for(int j = 10 ; j < 36 ; j++) mp[j] = (j - 10 + 'A');

        int n2 = n * n;
        int n3 = (n * n) * n;
        string s1 = "";
        string s2 = "";

        if(n2 == 0) s1 = "0";
        else {
                while(n2 > 0)
                {
                    s1 = mp[n2 % 16] + s1;
                    n2/=16;
                }
        }

        if(n3 == 0) s2 = "0";
        else {
                while(n3 > 0)
                {
                    s2 = mp[n3 % 36] + s2;
                    n3 /= 36;
                }
        }


        return s1 + s2;
    }
};