class Solution {
public:

     //a .bc|abcabcabcab|cabcabcab. c
     //     |abcabcabcab|
     

    bool repeatedSubstringPattern(string s) {

        int n=s.size();
        for(int i=1 ; i<= n/2 ; i++)
        {
            if(n % i == 0) //uneven length
            {
                string curr=s.substr(0,i);
                string concatinated="";
                for(int j=0 ; j< n/i ; j++)
                {
                    concatinated+=curr;
                }

                if(concatinated==s) return true;
            }
        }
        
        return false;
    }
};