class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

           
        int n=words.size();
        vector<int>prefix{0};
        vector<int>answer;

        int count=0;
        for(auto& elem : words){
            
            int l=elem.size();
            if((elem[0] == 'a' || elem[0] == 'e' || elem[0] == 'i' || elem[0] == 'o' || elem[0] == 'u') && (elem[l-1] == 'a' || elem[l-1] == 'e' || elem[l-1] == 'i' || elem[l-1] == 'o' || elem[l-1] == 'u'))
            {
                count++;
            }

            prefix.push_back(count);
        }

        for(auto elem : queries)
        {
            answer.push_back(prefix[elem[1]+1]-prefix[elem[0]]);
        }

        return answer;
    }
};