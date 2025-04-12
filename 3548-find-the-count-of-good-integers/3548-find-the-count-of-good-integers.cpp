class Solution {
public:
    set<string> st;
    long long fa[11] = {-1 , -1 , -1 , -1 , -1 , -1 , - 1, -1 , -1, -1 , -1};
    long long fact(int n){
        if(n == 0 || n == 1)return 1;
        if(fa[n] != -1)return fa[n];
        return fa[n] = n*1ll*fact(n - 1);
    }
    long long solve(int n , int k , int ind , string s){
        if(ind == (n + 1)/2){
            long num = stol(s);
            if(num % k == 0){
                unordered_map<char , int> m;
                for(int i = 0 ; i < n ; i++){
                    m[s[i]]++;
                }
                sort(s.begin() , s.end());
                if(st.find(s) != st.end())return 0;
                st.insert(s);
                long long deno = 1ll;
                for(auto &i : m){
                    deno *= fact(i.second);
                }
                long long red = (fact(n - 1)*1ll*m['0'])/deno;
                long long an = (1ll*fact(n))/deno;
                return an - red;
            }
            return 0;
        }
        long long ans = 0ll;
        for(int i = 0 ; i <= 9 ; i++){
            if(ind == 0 && i == 0 )continue;
            s[ind] = (i + '0');
            s[n - ind - 1] = s[ind];
            ans += solve(n , k , ind + 1 , s);
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        string s = "";
        for(int i = 0 ; i < n ; i++){
            s += '9';
        }
        return solve(n , k , 0 , s);
    }
};