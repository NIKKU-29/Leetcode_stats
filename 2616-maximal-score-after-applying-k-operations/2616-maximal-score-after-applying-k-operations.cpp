class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            int elem=pq.top();
            ans+=elem;
            if(elem==1)
            {
                ans+=(k-1-i);
                break;
            }
            pq.pop();
            pq.push((elem+2)/3);
        }
        return ans;
    }
};
