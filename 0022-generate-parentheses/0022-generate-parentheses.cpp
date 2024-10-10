// class Solution {
// public:


//     bool isvalid(string& current)
//     {
//        int counter=0;

//         for(auto elem : current)
//         {
//             if(elem=='(')
//             {
//                 counter++;
//             }

//             else if(counter>0 && elem ==')')
//             {
//                 counter--;
//             }

//             else{
//                 return false;
//             }

//         }

//         if(counter!=0) return false;

//         return true;
//     }

//     void solver(string curr , int siz , vector<string>&ans)
//     {
//         if(curr.size()==siz)
//         {
//             if(isvalid(curr))
//             {
//                 ans.push_back(curr);
//             }

//             return;
//         }

//         curr.push_back('(');
//         solver(curr,siz,ans);
//         curr.pop_back();
//         curr.push_back(')');
//         solver(curr,siz,ans);
//         curr.pop_back();

        
//     }

//     vector<string> generateParenthesis(int n) {

//         string curr="";
//         vector<string>ans;
//         solver(curr,n*2,ans);
//         return ans;
//     }
// };


class Solution {
public:

 void solver(string curr , int siz ,int open,int  close, vector<string>&ans)

    {
        if(curr.size()==siz)
        {
            ans.push_back(curr);
            return;
        }


        if(open < siz/2)
        {
        curr.push_back('(');
        solver(curr,siz,open+1,close,ans);
        curr.pop_back();

        }

        if(close < open)
        {
        curr.push_back(')');
        solver(curr,siz,open,close+1,ans);
        curr.pop_back();
        }


        
    }


    vector<string> generateParenthesis(int n) {

        string curr="";
        int open=0;
        int close=0;
        vector<string>ans;
        solver(curr,n*2,0,0,ans);
        return ans;
    }
};