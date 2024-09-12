class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st;
        int count=0;

        for(auto elem : allowed)
        {
            st.insert(elem);
        }

        for(auto elem : words)
        {
            for(int i=0;i<elem.size();i++)
            {
                if(st.find(elem[i])==st.end())
                {
                    break;
                }

                else if(i==elem.size()-1)
                {
                    count++;
                }
                
            }
        }

        return count;
        
    }
};