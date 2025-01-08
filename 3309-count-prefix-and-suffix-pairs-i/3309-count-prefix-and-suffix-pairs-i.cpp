class Solution {
public:


    bool isPrefixAndSuffix(string a , string b)
    {
         int n = a.size();
         int m = b.size();


        if (m < n) return false;
        return b.substr(0, n) == a && b.substr(m - n, n) == a;
    
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }

        return count;
    }
};