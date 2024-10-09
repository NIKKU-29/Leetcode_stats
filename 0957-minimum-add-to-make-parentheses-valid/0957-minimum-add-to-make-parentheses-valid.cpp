// class Solution {
// public:
//     int minAddToMakeValid(string s) {

//         stack<char>st;

//         for(auto elem : s)
//         {
//             if(st.empty())
//             {
//                 st.push(elem);
//             }

//             else{

//                     if(st.top()=='(' && elem == ')')
//                     {
//                         st.pop();
//                     }

//                     else{

//                         st.push(elem);
//                     }

//             }
//         }

//         return st.size();
//     }
// };


class Solution {
public:
    int minAddToMakeValid(string s) {

        int o_count=0;
        int adds=0;

        for(auto elem : s)
        {
            if(elem == '(')
            {
                o_count++;
            }

            else{

                if(o_count > 0) o_count--;
                else adds++;
            }
        }


        return o_count+adds;
    }
};