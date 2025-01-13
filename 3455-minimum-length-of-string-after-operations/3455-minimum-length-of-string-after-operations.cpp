class Solution {
public:
    int minimumLength(string s) {

        vector<int>vec(26,0);

        for(auto elem : s)
        {
            vec[elem-'a']++;
        }

        int count=0;

        for(auto elem : vec)
        {
            if(elem >= 3)
            {
                int num=elem;

                while(num >= 3)
                {
                    count+=2;
                    num-=2;
                }
            }
        }

        return s.size()-count;   
    }
};