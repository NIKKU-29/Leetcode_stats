class Solution {
public:

    // bool palindrom(int i,int j,string& s)
    // {
    //     if(i>=j) 
    //     {
    //         return true;
    //     }

    //     if(s[i]==s[j])
    //     {
    //         return palindrom(i+1,j-1,s);
    //     }


    //     return false;
    // }

    // string longestPalindrome(string s) {

    //    int n=s.size();
    //     int maxL=1;
    //     int idx=0;

    //     for(int i=0 ;i< n ;i++)
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             if(palindrom(i,j,s))
    //             {
    //                 if(j-i+1 > maxL)
    //                 {
    //                     maxL=j-i+1;
    //                     idx=i;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(idx,maxL);
//      }
//};

    string longestPalindrome(string s) {
        
        int maxL=1;
        int idx=0;
        int n=s.size();

        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0 ;i< n;i++)
        {
            dp[i][i]=true;
        }


        for(int len=2 ; len<=n;len++)
        {
            for(int i=0 ;i<n-len+1;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j] && len==2)
                {
                    dp[i][j]=true;
                    maxL=2;
                    idx=i;
                }

                else if(s[i]==s[j] && dp[i+1][j-1]) 
//yahe par sirf i+1 and j-1 dp ko check karke hame pata
//laga sakte hai ki kya jo abhi badi string hai
//vo palindrom hai ya nahi kuki agar curr i and j dono
//barbar hai to i+1 and j-1 check karo ki vo barbar
//hai ya nhai kuki agar vo plaindrom honge 
//hqamne phele hi true mark kar rakha honge
// kuki jab i + diff == j hua hoga tab hamne
//check kar klia hoga ki vo plaindrom hai ya nahi 
// if i = 2 and j = 5 check ho rah hai to jab diff == 3
//hoga tba ham ye check kar chuke honge
//kuki ab diff == 4 hai jo bad a hai aur diff 3 vale already
//calculate honge
                {
                    dp[i][j]=true;
                    if(j-i+1 > maxL)
                    {    
                        maxL=j-i+1;
                        idx=i;
                    }
                }
            }
        }

        return s.substr(idx,maxL);
    }
};