class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();
        vector<int>ans;
        
        for(int i=0 ; i < n-1 ; i++)
        {
            bool done=false;
            for(int j=i+1; j < n ; j++)
            {
                if(prices[j]<=prices[i])
                {
                    ans.push_back(prices[i]-prices[j]);
                    done=true;
                    break;
                }
            }

            if(done==false) ans.push_back(prices[i]);
        }
        ans.push_back(prices[n-1]);
        return ans;
        
    }
};