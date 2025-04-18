class Solution {
public:
    string countAndSay(int n) {

        if(n == 1) return "1";
        string curr = "1";

        for(int k = 1 ; k<n ; k++)
        {
            int count = 0;
            string ans = "";

            for(int i = 0 ; i < curr.size() ; i++)
            {
                if(i == 0 || curr[i] == curr[i-1])
                {
                    count++;
                }

                else
                {
                    ans+= to_string(count) + curr[i-1];
                    count =1;
                }
            }

            ans += to_string(count) + curr.back();
            curr= ans;

        }

        return curr;
        
    }
};

// class Solution {
// public:

//     void solver(int idx,string& curr,string& ans,int& prev,int& count)
//     {
//         if(idx == curr.size()) //elemnst which are at last and are similar are left naddd so we add them here
//         {
//             ans+=to_string(count);
//             ans+= to_string(prev);
//             return;
//         }

//         int digit = curr[idx] - '0';
//         if (prev == -1 || prev == digit)
//         {
//             count++;
//             prev = digit;
//             solver(idx+1,curr,ans,prev,count);   
//         }

//         else{  
//                int digit = curr[idx] - '0';
//                 ans += to_string(count);
//                 ans += to_string(prev);
//                 count = 1;
//                 prev = digit;
//                 solver(idx + 1, curr, ans, prev, count);
//         }
//     }

//     string countAndSay(int n) {

//         string curr = "1";
//         string ans = "";
//         int prev,count;
        
//         if(n == 1) return curr;

//         for(int i = 1 ; i < n ; i++)
//         {
//             prev = -1;  
//             count = 0;
//             ans= "";
//             solver(0,curr,ans,prev,count); 
//             curr = ans;
//         }
//         return ans;
//     }
// };