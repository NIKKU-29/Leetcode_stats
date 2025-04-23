class Solution {
public:
    int countLargestGroup(int n) {

        unordered_map<int,int>mp;
        int maxi = INT_MIN;

        for(int i=1 ; i <= n ; i++)
        {
            int sum = 0;
            int temp = i;
            
            while(temp)
            {
                sum+= (temp % 10);
                temp/=10;
                // cout<<sum;
            }

            mp[sum]++;
            maxi = max(maxi,mp[sum]);
        }

        int count = 0;

        for(auto elem : mp)
        {
            if(elem.second == maxi) count++;
        }

        return count;
        
        return 0;
    }
};