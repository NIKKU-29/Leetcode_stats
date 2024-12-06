class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        int sum=0;
        unordered_set<int>st;
        int count=0;

        for(auto elem : banned)
        {
            st.insert(elem);
        }

        for(int i=1 ; i <= n ; i++)
        {
            if(!st.count(i))
            {
                cout<<i<<endl;
                if(sum+i <= maxSum) 
                {
                    sum+=i;
                    count++;
                }
                else break;
            }
        }
        
        return count;
    }
};