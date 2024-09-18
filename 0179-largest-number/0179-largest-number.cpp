class Solution {
public:

    static bool comp(const string& a,const string& b)
    {
        if( a + b > b + a) return true;

        else return false;
    }


    string largestNumber(vector<int>& nums) {


        vector<string>vec;

        for(auto elem : nums)
        {
            vec.push_back(to_string(elem));
        }

            sort(vec.begin(),vec.end(),comp);

            string ans="";

            for(auto elem : vec)
            {
                ans+=elem;
            }

            if(stoi(ans)==0)
            {
                return "0";
            }

        return ans;
    }
};