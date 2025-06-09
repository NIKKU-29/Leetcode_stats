class Solution {
public:
    int counter(long curr, long next, int limit) {
        int siblings = 0;

        while (curr <= limit) {
            siblings += min((long)(limit + 1), next) - curr;
            curr *= 10;
            next *= 10;
        }

        return siblings;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int border = curr + 1;
            int brothers = counter(curr, border, n);  

            if (brothers <= k) {
                curr++;
                k -= brothers;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
