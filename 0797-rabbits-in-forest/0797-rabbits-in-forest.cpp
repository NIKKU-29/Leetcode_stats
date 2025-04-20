// class Solution {
// public:
//     int numRabbits(vector<int>& answers) {
        
//         /*
//             1->2                  2->3                  3->4
//             1,1->2                2,2->3                3,3->4 
//             1,1,1->4              2,2,2->3              3,3,3->4
//             1,1,1,1->4            2,2,2,2->6            3,3,3,3->4
//             1,1,1,1,1->6          2,2,2,2,2->6          3,3,3,3,3->8
               
//             1 wouch for 1         2 wouch for 3         3 wouch for 4
//             1,1 wouch for 2       2,2 wouch for 3..      ............
//             1,1,1 woucch for 4    ................ 


//             similary u can observe that  num wouch for num + 1 rabits
//             whem u have found how many num + 1 rabist u have
//             just calculate how many of them are wouching for each other
//             which is simple as doing % of count with num+1
//             then the left rabbits woudl wouch for each other at min
//             giving num +1

//                     int d = count / (num + 1);
//                     int q = count % (num + 1);
//                     sum+= d*(num + 1);

//                     if(q) sum+=(num+1);


//                     here we can also use ceil but we have to convert the divin in double 


//         */


//             map<int,int>mp;
//             for(auto elem : answers)
//             {
//                 mp[elem]++;
//             }

//             int sum = 0;

//             for(auto elem : mp)
//             {
//                 int num = elem.first;
//                 int count = elem.second;

//                 if(count <= num + 1 )
//                 {
//                     sum+=(num+1);
//                 }

//                 else{
                    
//                     int d = count / (num + 1);
//                     int q = count % (num + 1);
//                     sum+= d*(num + 1);

//                     if(q) sum+=(num+1);

//                 }
//             }

//         return sum;
//     }
// };



class Solution {
public:
    int numRabbits(vector<int>& nums, int total = 0) {
        unordered_map <int,int> mpp;
        for (int i : nums) mpp[i]++;

        for (auto& p : mpp)
        total += ceil((float)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};