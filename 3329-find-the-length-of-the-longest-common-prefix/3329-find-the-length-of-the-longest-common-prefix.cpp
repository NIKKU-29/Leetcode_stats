
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        // Store all prefixes of numbers in arr1
        for (auto elem : arr1) {
            while (elem != 0) {
                st.insert(elem);
                elem /= 10; // Remove the last digit
            }
        }

        int maxi = 0;

        for (auto elem : arr2) {
          
            int temp = elem;

            while(temp!=0)
            {
                if (st.count(temp)) {
                    maxi = max(maxi, (int)to_string(temp).length());
            }
                temp /= 10; 
        }

        }

        return maxi;
    }
};