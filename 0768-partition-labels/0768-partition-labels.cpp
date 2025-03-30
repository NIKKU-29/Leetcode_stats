class Solution {
public:
    vector<int> partitionLabels(string s) {
        //try to hold rightmos occurance of every caharcter
        int n = s.size();
        vector<int>RightMostIndex(26,0);

        for(int i = 0 ;i<n ;i++)
        {
            RightMostIndex[s[i] - 'a' ] = i;
        }
        
        vector<int>ans;
        int limit = RightMostIndex[s[0] - 'a'];
        
        int prev = 0;

        for(int i=0 ;i< n ;i++)
        {
              limit = max(limit,RightMostIndex[s[i] - 'a']);
              
              if(i == limit && i < n)
              {
                    ans.push_back((limit+1) - prev);
                    prev = limit+1;
              } 
        }

        return ans;
    }
};