class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string ans="";

        int n=s.size();
        int m=spaces.size();
        int j=0;
        for(int i=0 ; i< n ;i++)
        {
            if( j<m && i == spaces[j])
            {
                ans+=" ";
                j++;
                i--;
            }

            else{
                ans+= s[i];
            }
        }

        return ans;
        
    }
};