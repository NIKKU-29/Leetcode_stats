class Solution {
public:

    typedef long long ll;

    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<ll,vector<ll>,greater<ll>>pq;

        for(auto elem : nums) pq.push(elem);

        int count=0;

        while(pq.top() < k && pq.size() >= 2)
        {
            ll s1=pq.top();
            pq.pop();
            ll s2=pq.top();
            pq.pop();

            ll value= (min(s1,s2) * 2) + max(s1,s2);
            count++;
            pq.push(value);
            // cout<<value<<" ";
        }


        return count;
        
    }
};