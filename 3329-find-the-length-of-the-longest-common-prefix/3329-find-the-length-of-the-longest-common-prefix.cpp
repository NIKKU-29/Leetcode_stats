
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

        // Check prefixes of numbers in arr2
        for (auto elem : arr2) {
            // Store the original value for prefix length calculation
            int temp = elem;
            while (temp != 0) {
                if (st.count(temp)) {
                    maxi = max(maxi, (int)to_string(temp).length()); // Update maximum length
                }
                temp /= 10; // Remove the last digit
            }
        }

        return maxi;
    }
};