class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int n=values.size();
        int add=values[0];
        int ans=INT_MIN;


        for(int i=1 ; i< n ;i++)
        {
            ans=max(ans, add + values[i]-i);
            add=max(add,values[i]+i);
        }

        return ans;
        
    }
};