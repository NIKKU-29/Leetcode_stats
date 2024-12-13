class Solution {
public:

    struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        
        if (a.first == b.first) {
            
            return a.second > b.second;
        }
       
        return a.first > b.first;
    }
};

    long long findScore(vector<int>& nums) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
        int n=nums.size();
        vector<bool> visited(n, false);

        for(int i=0 ; i < n ; i++)
        {
            pq.push({nums[i],i});
        }

        long long sum=0;
        
        while(!pq.empty())
        {
            auto elem = pq.top();
            int num = elem.first;
            int idx = elem.second;
            pq.pop();

            if(visited[idx])
            {
                continue;
            }

            else{

                visited[idx]=true;
                sum+=num;

                if(idx + 1 < n && !visited[idx+1])
                {
                    visited[idx+1]=true;
                }

                if(idx - 1 >= 0 && !visited[idx-1])
                {
                    visited[idx-1]=true;
                }

            }

        }

        return sum;
    }
};