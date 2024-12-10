class Solution {
public:

    bool issame(string s)
    {
        unordered_map<char,int>mp;

        for(auto elem : s)
        {
            mp[elem]++;
        }

        if(mp.size()==1) return true;
        return false;
    }


    int maximumLength(string s) {

       unordered_map<string,int>mp;
        int n=s.size();

       for(int i=0 ; i < n ; i++)
       {
            string curr="";
            

            for(int j = i ; j < n ; j++ )
            {
                curr+=s[j];

                if(issame(curr))
                {
                    mp[curr]++;
                }
            }
       }  

          int maxlength=-1;

            for(auto elem : mp)
            {
                if(elem.second >=3)
                {
                    maxlength=max(maxlength,(int)elem.first.size());
                }
            }
     

        return maxlength;
      
    }
};