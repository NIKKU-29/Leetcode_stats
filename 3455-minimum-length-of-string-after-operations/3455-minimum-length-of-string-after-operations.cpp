#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        // Count the frequency of each character in the string
        for (auto elem : s) {
            mp[elem]++;
        }

        // Reduce the frequency count based on the given rule
        for (auto& elem : mp) { // Use reference to update the map correctly
            while (elem.second / 3) {
                elem.second -= 2;
            }
        }

        int count = 0;

        // Calculate the resulting length of the string
        for (auto& elem : mp) {
            count += elem.second;
        }
        
        return count;
    }
};
