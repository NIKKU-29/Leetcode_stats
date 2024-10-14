class Solution {
public:
        void solver(int i , string temp,string digits,unordered_map<int,string>&mp,vector<string>&ans)
        {

            if(i==digits.size())
            {
                ans.push_back(temp);
                return;
            }
            

            char elem = digits[i];
            string act=mp[elem];

            for(auto ele : act)
            {
                solver(i+1,temp + ele,digits,mp,ans);
            }

            
        }


    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        unordered_map<int,string>mp;

            mp['2']="abc";
            mp['3']="def";
            mp['4']="ghi";
            mp['5']="jkl";
            mp['6']="mno";
            mp['7']="pqrs";
            mp['8']="tuv";
            mp['9']="wxyz";
    
        vector<string>ans;
      
        solver(0,"",digits,mp,ans);

        return ans;
        
    }
};