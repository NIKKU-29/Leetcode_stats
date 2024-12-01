class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<float,int>mp;

        for(auto elem : arr)
        {
            mp[elem]++;
        }


        for(auto num : arr)
        {
            if(mp.count(num*2) || (num%2==0 && mp.count(num/2)))
            {
                if(num==0 && mp[num]<2) continue; 
                return true;
            }
        }

        
        return false;
    }
};