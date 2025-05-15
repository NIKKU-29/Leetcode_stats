class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

            int n = groups.size();
            
            vector<int>longest;

            for(int i = 0 ; i < n ; i++)
            {
                
                vector<int>curr;
                curr.push_back(i);
                int select = groups[i];

                for(int j = i + 1 ; j < n ; j++)
                {
                    if(groups[j] != select)
                    {
                        curr.push_back(j);
                        select=!select;
                    }

                }

                if((int)longest.size() < (int)curr.size())
                {
                    longest = curr;
                }
            }

            vector<string>ans;

            for(auto elem : longest)
            {
                ans.push_back(words[elem]);
            }


            return ans;

    }
};