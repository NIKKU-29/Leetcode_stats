class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501);
        int ans = -1;
        for(auto elem : arr) freq[elem]++;
        for(int i = 1 ; i< 500 ; i++) 
            if(i == freq[i]) ans = max(ans,i);
        return ans;
    }   
};