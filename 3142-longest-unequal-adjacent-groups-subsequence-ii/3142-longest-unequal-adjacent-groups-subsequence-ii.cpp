class Solution {
public:
     bool check(string &a,string &b)
    {
        int n=a.size()-1,m=b.size()-1;
        if(n!=m)
            return 0;
        int c=0;
        while(n>=0)
        {
            if(a[n]!=b[n])
                c++;
            n--;
        }
        return c==1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        int n = words.size();
     vector<int>dp(n+1,1);
        vector<int>prev(n+1,-1);
        int maxdp=1,maxprev=0;
        for(int i=0;i<n;i++)
        {   
            for(int j=i-1;j>=0;j--)
            {
                string a=words[i],b=words[j];
                if(groups[j]!=groups[i])
                {
                    bool k=check(a,b);
                    if(k)
                    {   
                        if(1+dp[j]>dp[i])
                        {
                            dp[i]=1+dp[j];
                            prev[i]=j;
                            if(dp[i]>maxdp)
                            {
                                maxdp=dp[i];
                                maxprev=i;
                            }
                        }
                    }
                }
            }
        }
        vector<string>res;
        res.push_back(words[maxprev]);
        while(prev[maxprev]!=-1)
        {
            res.push_back(words[prev[maxprev]]);
            maxprev=prev[maxprev];
        }
        reverse(res.begin(),res.end());
        return res;
       
    }
};