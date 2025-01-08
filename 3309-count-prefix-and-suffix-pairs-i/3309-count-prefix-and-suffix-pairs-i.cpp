class Solution {
public:


    bool isPrefixAndSuffix(string a , string b)
    {
        int n=a.size();
        int N=b.size();
        int i=0;

        string prefix="";
        string suffix="";

        while(i<N)
        {
            
            if(i>=0 && i<= n-1) 
            {
                prefix+=b[i];
            }

            if(i>= N-n &&  i<N)
            {
                suffix+=b[i];
                
            }

            i++;

        }

        if(prefix == suffix && prefix == a)
        {
            return true;
        }

        return false;

    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n=words.size();
        int count=0;

        for(int i=0 ; i< n ;i++)
        {
            for(int j=0 ; j< n ; j++)
            {
                if(words[j].size() < words[i].size())
                {
                    continue;
                }

                if(i!=j && i<j)
                {
                    cout<<"hi3-";
                    count+=isPrefixAndSuffix(words[i],words[j]) == true ? 1 : 0;
                }
            }
        }

        return count;
    }
};