class Solution {
public:
    int f(vector<int>& nums2, long long p1, long long v) {
        
        int n2 = nums2.size();
        
        int l = 0, r = n2 - 1;
        
        while (l <= r) 
        {
            int mid = (l + r) / 2;
            if (p1 >= 0 && nums2[mid] * p1 <= v || p1 < 0 && nums2[mid] * p1 > v) l = mid +1;
            else r = mid - 1;
        }

        if (p1 >= 0) return l;
        else return n2 - l;
        
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long l = -1e10, r = 1e10;
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};