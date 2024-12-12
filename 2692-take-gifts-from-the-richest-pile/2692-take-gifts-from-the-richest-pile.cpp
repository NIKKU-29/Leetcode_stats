class Solution {
public:

    long long pickGifts(vector<int>& gifts, int k) {

        int n=gifts.size();
        priority_queue<int,vector<int>>pq;

        for(auto elem : gifts)
        {
            pq.push(elem);
        }

        while(k--)
        {
            int val=pq.top();
            pq.pop();
            pq.push(sqrt(val));
        }

        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        
        return sum;
    }
};