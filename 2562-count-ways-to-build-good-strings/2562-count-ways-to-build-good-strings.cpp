class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod=1e9+7;
        int dp[100001]={0};
        dp[0]=1;
        for(int i=1; i<=high; i++){
            long long ans=1;
            if (i>=zero) ans+=dp[i-zero];
            if (i>=one) ans+=dp[i-one];
            dp[i]=ans%mod;
        }
        return (dp[high]-dp[low-1]+mod)%mod;
    }
};