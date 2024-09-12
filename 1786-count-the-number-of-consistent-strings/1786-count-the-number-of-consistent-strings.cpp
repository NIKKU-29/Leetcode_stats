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
            bool valid=true;

            for(int i=0;i<elem.size();i++)
            {
                while(st.find(elem[i])==st.end())
                {
                    valid=false;
                    break;
                }
            }

            if(valid==true)
            {
                count++;
            }
        }

        return count;
        
    }
};