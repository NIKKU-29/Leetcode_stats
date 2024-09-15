class Solution {
public:

    bool checker(string & joined)
    {
        int start=0;
        int end=joined.size()-1;

        while(start<=end)
        {
            if(joined[start]==joined[end])
            {
                start++;
                end--;
            }

            else{

                return false;
            }
        }

        return true;
    }

    bool isPalindrome(string s) {

        string joined="";

        for(auto elem : s)
        {
            if(isalnum(elem))
            {
                joined.push_back(tolower(elem));
            }
        }
        
        return checker(joined);
    }
};