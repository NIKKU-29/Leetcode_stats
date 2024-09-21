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

class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int>Order;
        int currnum=1;

        for(int i=0;i<n;i++)
        {
            Order.push_back(currnum);

            if(currnum*10 <= n)
            {
                currnum*=10;
            }

            else
            {
                if(currnum%10 == 9 || currnum>=n)
                {
                    currnum/=10;
                }
                
                currnum+=1;
            }
        }

        return Order;
    }
};