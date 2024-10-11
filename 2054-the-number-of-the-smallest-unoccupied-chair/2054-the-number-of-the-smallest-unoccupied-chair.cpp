// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {

//         int n=times.size();
//         vector<int>chairs(n,-1);

//         int target=times[targetFriend][0];
//         sort(times.begin(),times.end());

//         for(auto elem : times)
//         {
//             int arrival=elem[0];
//             int dpart=elem[1];

//             for(int i=0 ; i<n ;i++)
//             {
//                 if(chairs[i] <= arrival)
//                 {
//                     chairs[i]=dpart;

//                     if(arrival==target)
//                     {
//                         return i;
//                     }

//                     break;
//                 }

//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    typedef pair<int, int> P;
    typedef int i;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();

        priority_queue<P, vector<P>, greater<P>> occupied;
        priority_queue<i, vector<i>, greater<i>> chairs;

        int target = times[targetFriend][0];

        sort(begin(times), end(times));

        int chair_num = 0;

        for (auto elem : times) {
            int arrival = elem[0];
            int depart = elem[1];

            while (!occupied.empty() && occupied.top().first <= arrival) {
                chairs.push(occupied.top().second);
                occupied.pop();
            }

            if (chairs.empty()) {
                occupied.push({depart, chair_num});

                if (arrival == target) {
                    return chair_num;
                }

                chair_num++;

            }

            else {

                int givenchair = chairs.top();
                chairs.pop();

                if (arrival == target) {
                    return givenchair;
                }
                occupied.push({depart, givenchair});
            }
        }

        return -1;
    }
};