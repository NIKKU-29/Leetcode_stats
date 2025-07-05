class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501,0);
        bool occ = false;
        int ans = 0;
        for(auto elem : arr) freq[elem]++;
        for(int i = 1 ; i< 500 ; i++) 
            if(i == freq[i]) 
            {
                occ = true;
                ans = max(ans,i);
            }


        return occ ? ans : -1;
    }   
};