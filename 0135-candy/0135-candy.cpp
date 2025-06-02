class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> holder(n, 1); // initialize everyone with 1 candy

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                holder[i] = holder[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                holder[i] = max(holder[i], holder[i + 1] + 1);
            }
        }

        return accumulate(holder.begin(), holder.end(), 0);
    }
};
