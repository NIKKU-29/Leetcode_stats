class Solution {
public:
    int maxScore(string s) {

        int count0=0;
        int count1=0;
        int n=s.size();

        for(auto elem : s)
        {
            if(elem=='1') count1++;
        }

        // if(s[0]=='0') count0++;
        // if(s[0]=='1') count1--;

        int maxi=INT_MIN;

        for(int i=0 ; i< n-1 ;i++)
        {
            if(s[i]=='1') count1--;
            if(s[i]=='0') count0++;   
            maxi=max(maxi,(count0+count1));
        }

        return maxi;
        
    }
};