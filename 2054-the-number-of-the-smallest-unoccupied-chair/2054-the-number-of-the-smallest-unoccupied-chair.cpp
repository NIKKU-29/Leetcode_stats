class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n=times.size();
        vector<int>chairs(n,-1);

        int target=times[targetFriend][0];
        sort(times.begin(),times.end());


        for(auto elem : times)
        {
            int arrival=elem[0];
            int dpart=elem[1];

            for(int i=0 ; i<n ;i++)
            {
                if(chairs[i] <= arrival)
                {
                    chairs[i]=dpart;

                    if(arrival==target)
                    {
                        return i;
                    }

                    break;
                }

            }
        }


        return -1;
    }
};