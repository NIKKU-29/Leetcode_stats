class Solution {
public:
    long long coloredCells(int n) {
        
        long long start = 1;
        long long incremetor=0;

        while(n--)
        {
            start+=incremetor;
            incremetor+=4;
        }

        return start;

    }
};