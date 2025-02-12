class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> digitsum;

        for (auto elem : nums) {
            int sum = 0;
            while (elem != 0) {
                sum += elem % 10;
                elem = elem / 10;
            }

            digitsum.push_back(sum);
            // cout<<sum<<" ";
        }

        vector<int> mp(82,-1);

        int ans = -1;

        for (int i = 0; i < n; i++) {
            int sum = digitsum[i];
            int value = nums[i];

            if (mp[sum]==-1) {
                mp[sum] = value;
            }

            else {
                int sumoftwo = mp[sum] + value;
                ans = max(ans, sumoftwo);
                mp[sum] = max(mp[sum], value);
            }
        }

        return ans;
    }
};