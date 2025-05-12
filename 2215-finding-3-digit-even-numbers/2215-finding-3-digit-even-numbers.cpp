#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

class Solution {
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
        std::set<int> ans_set;
        std::map<int, int> counts;
        for (int digit : digits) {
            counts[digit]++;
        }

        for (int i = 1; i <= 9; ++i) {
            if (counts[i] > 0) {
                counts[i]--;
                for (int j = 0; j <= 9; ++j) {
                    if (counts[j] > 0) {
                        counts[j]--;
                        for (int k = 0; k <= 8; k += 2) {
                            if (counts[k] > 0) {
                                ans_set.insert(i * 100 + j * 10 + k);
                            }
                        }
                        counts[j]++; // Backtrack
                    }
                }
                counts[i]++; // Backtrack
            }
        }

        std::vector<int> ans(ans_set.begin(), ans_set.end());
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};