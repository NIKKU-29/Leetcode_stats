class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        set<char>st={'a','e','i','o','u'};    
        int n=words.size();
        vector<int>prefix;
        vector<int>answer;

        int count=0;
        for(auto& elem : words){
            
            int l=elem.size();
            if(st.count(elem[0]) && st.count(elem[l-1]))
            {
                count++;
            }

            prefix.push_back(count);
        }

        for(auto elem : queries)
        {
            if(elem[0]==elem[1] && elem[1]==0)
            {
                answer.push_back(0);
            }

            else if(elem[0]!=elem[1])
            {
                if(elem[0]==0) answer.push_back(prefix[elem[1]]);   
                else answer.push_back(prefix[elem[1]]-prefix[elem[0]-1]);           
            }

            else{
                    answer.push_back(prefix[elem[1]]-prefix[elem[0]-1]);
            }
        }

        return answer;
    }
};