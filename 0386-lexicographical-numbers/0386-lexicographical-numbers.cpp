class Solution {
public:

    static bool comp(const int & a, const int & b)
    {
         return to_string(a) < to_string(b);
    }

    vector<int> lexicalOrder(int n) {

        vector<int>vec(n);
        iota(vec.begin(),vec.end(),1);

        sort(vec.begin(),vec.end(),comp);


        return vec;
        
    }
};