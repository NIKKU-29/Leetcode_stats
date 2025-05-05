class Solution {
public:

    const int mod= 1e9 + 7; 

    int numTilings(int n) {
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        vector<long long>a(n+1);
        a[1] = 1;
        a[2] = 2;
        a[3] = 5;

        for(int i = 4 ; i <= n ; i++)
        {
            a[i] = a[i-3] + (2 *a[i-1] % mod);
            a[i]%=mod;
        }

        return a[n];


    }
};