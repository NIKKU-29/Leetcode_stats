class Solution {
public:

        typedef long long l;

    l maxKelements(vector<int>& nums, int k) {

        priority_queue<l>pq;
        l ans=0;


        for(l elem : nums)
        {
            pq.push(elem);
        }

        while(k)
        {
            l elem=pq.top();
            cout<<elem<<"-->";
            ans+=elem;
            pq.pop();
            l val=ceil((double)elem/3);
            cout<<val;
            cout<<endl;
            pq.push(val);
            k--;
        }


        return ans;
        
    }
};