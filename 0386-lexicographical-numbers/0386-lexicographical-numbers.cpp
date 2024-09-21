// class Solution {
// public:

//     static bool comp(const int & a, const int & b) {
//         return to_string(a) < to_string(b);
//     }
    
//     vector<int> lexicalOrder(int n) {

//         vector<int>vec(n);
//         iota(vec.begin(),vec.end(),1);
//         sort(vec.begin(),vec.end(),comp);
//         return vec;
        
//     }
// };

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {

//         vector<int>Order;
//         int currnum=1;

//         for(int i=0;i<n;i++)
//         {
//             Order.push_back(currnum);

//             if(currnum*10 <= n)
//             {
//                 currnum*=10;
//             }

//             else
//             {
//                 while(currnum%10 == 9 || currnum>=n)
//                 {
//                     currnum/=10;
//                 }
                
//                 currnum+=1;
//             }
//         }

//         return Order;
//     }
// };

class Solution {
public:

    void solve(int curr,int n,vector<int>& ans)
    {
        if(curr>n) return;

        ans.push_back(curr);


        for(int i=0;i<=9;i++)
        {
            if(curr*10 + i > n)
            {
                return;
            }

            solve(curr*10 + i , n , ans);
        }
    }


    vector<int> lexicalOrder(int n) {

        vector<int>ans;

        for(int start=1;start<=9;start++)
        {
            solve(start,n,ans);
        }


        return ans;
        
    }
};