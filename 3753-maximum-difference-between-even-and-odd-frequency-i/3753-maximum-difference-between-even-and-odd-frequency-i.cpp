class Solution {
public:
    int maxDifference(string s) {

        vector<int>mp(26,0);

        for(auto elem : s)
        {
            mp[elem - 'a']++;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto elem : mp)
        {
            if(elem % 2)
            {
                maxi = max(maxi,elem);
                // cout<<maxi<<">>>";
                // cout<<endl;
            }

            else if(elem > 0 )
            {
                mini = min(mini,elem); 
                // cout<<mini<<"<<<<";
                // cout<<endl;   
            }
        }

        

        return maxi - mini;

    }
};