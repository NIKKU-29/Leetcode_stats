class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int,int>mp;

        for(auto elem : arr)
        {
            int mod= ( elem % k + k) % k;
            mp[mod]++;
        }



        for(int i=1;i<arr.size();i++)
        {
            int mod =  ( arr[i] % k + k) % k ;
            int target = k - mod;
        
        if(mod==0)
        {
            if(mp[mod]%2!=0) return false;
        }
            
        else if(mp[target]!=mp[mod])
            {
                return false;
            }
        }


    return true;
        
    }
};