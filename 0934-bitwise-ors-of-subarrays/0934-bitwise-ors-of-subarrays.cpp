class Solution {
public:
    int subarrayBitwiseORs( vector<int>& arr) {
        
    unordered_set<int> result ;
    unordered_set<int> current ;

    for (int x : arr) {
        
        unordered_set<int> next ;
        
        next .insert(x);

        for (int y : current ) {
            next .insert(x | y);
        }

        
        result .insert(next .begin(), next .end());
        
            current  = next ;
    }

        return result .size();
    }
};